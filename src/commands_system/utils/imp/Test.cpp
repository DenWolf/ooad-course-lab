#ifdef COMPILE_WITH_TESTS



#define _CRTDBG_MAP_ALLOC 1
#include <stdlib.h>
#include <crtdbg.h>
#include <excpt.h>




#include "../Test.h"
#include "../Exception.h"

#include <stddef.h>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <typeinfo>




using std::vector;
using std::string;


static vector<Test *> *ptr_tests = nullptr;


static const char *const parts[] = {
	"before", "test", "after"
};



struct locals_t {
	size_t *i, *part, *tests_ok;
	Test **test;
};








static string format_typeid_name(const string &name) {
  size_t i;
	if ((i = name.find_first_of(' ')) != string::npos) {
		return name.substr(i+1);
	}
	return name;
}






static void show_failed_test(Test *test, size_t part) {
	std::cerr <<
		typeid(*test).name() << "." << parts[part] << "(): FATAL ERROR\n";
}







static void check_at_end(size_t tests_ok) {
  vector<Test *> &tests = *ptr_tests;
  size_t size = tests.size();
	tests.clear();
	delete ptr_tests;

	if (tests_ok != size) {
		std::cerr << tests_ok << "/" << size << " tests ok\n";
		{
		  string line;
			std::getline(std::cin, line);
		}
		exit(1);
	}

	if (_CrtDumpMemoryLeaks())
		std::cerr << "memory leak after all tests";
}








class MemoryLeakException : public Exception {
public:
	MemoryLeakException() : Exception(nullptr) {}
};







void Test::All_inner(void *locals) {
  locals_t &l = *static_cast<locals_t*>(locals);
  size_t &i = *l.i, &part = *l.part, &tests_ok = *l.tests_ok;
  Test *&test = *l.test;

  vector<Test *> &tests = *ptr_tests;

	while (i < tests.size()) {
		try {
			if (part <= 1)
				part = 2, ++i, test->after();

			{
			  _CrtMemState s1, s2, s3;
			  _CrtMemCheckpoint(&s1);

				for (; i < tests.size(); ++i) {
					test = tests[i];
					part = 0; test->before();
					part = 1; test->do_test();
					part = 2; test->after();
					_CrtMemCheckpoint(&s2);
					if (_CrtMemDifference( &s3, &s1, &s2))
						throw MemoryLeakException();
					++tests_ok;
				}
			}
		} catch (const Exception &e) {
			std::cerr <<
				format_typeid_name(typeid(*test).name()) <<
				"." << parts[part] << "(): " <<
				format_typeid_name(typeid(e).name());

			if (e.what()) {
				std::cerr << "{\"" << e.what() << "\"}";
			}

			std::cerr << '\n';

			if (part == 2) ++i;
		}
	}
}



void Test::All() {
	if (ptr_tests != nullptr) {
	  size_t i = 0, part = 2, tests_ok = 0;
	  Test *test = NULL;
	  locals_t l = {&i, &part, &tests_ok, &test};

		__try {
			All_inner(&l);
		} __except (show_failed_test(test, part), EXCEPTION_CONTINUE_SEARCH) {
		}

		check_at_end(tests_ok);
	}
}








Test::Test() {
	if (ptr_tests == nullptr) ptr_tests = new vector<Test *>;
	ptr_tests->push_back(this);
}

void Test::before() {}
void Test::do_test() {test();}
void Test::after() {}




class HasNotThrownException : public Exception {
public:
	HasNotThrownException() : Exception("") {}
};

void Test::throw_no_exception() {
	throw HasNotThrownException();
}




#endif

