#include "../IDataBase.h"
#include <fstream>
#include <string>
#include <unordered_map>



#ifdef COMPILE_WITH_TESTS
	struct _TestOnly {int x;};
	#define TESTONLY (_TestOnly*)nullptr
#endif


class DataBase: public IDataBase {
private:
  std::unordered_map<std::string, std::fstream *> files;
  bool opened;

	void insert_to_files(const std::string &);
	void insert_files();
	void delete_files();

	// �� ������������
	void operator =(const DataBase &);
	DataBase(const DataBase &);

public:
	virtual void open();
	virtual void close();
	virtual const class ITable * perform(const class IQuery &query);
	virtual ~DataBase();

	static void CreateInstance();
	static void DeleteInstance();

	DataBase();
	std::fstream & getTableFile(const std::string &name_of_table);
	void clearTableFile(const std::string &name_of_table);


#ifdef COMPILE_WITH_TESTS
  bool testOnly;
	void __insert_test();
	static void CreateTestInstance();
	DataBase(_TestOnly *);
#endif
};

