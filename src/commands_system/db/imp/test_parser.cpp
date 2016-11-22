#include "parser.h"
#include "ParseFailedException.h"
#include "../Element.h"

#include "../../utils/Test.h"
#include "../../utils/Assertions.h"


#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;


TEST(CanParse) {
	void test() {
		parse(ifstream("data/test.txt"));
	}
} TEST_END;


TEST(CanParseUsers) {
	void test() {
	  TableWithHeader t = parse(ifstream("data/test.txt"));
		assertTrue(t.content.size()!=0);
	}
} TEST_END;


TEST_exception(CannotParseNotExistingFile, ParseFailedException) {
	void test() {
		parse(ifstream("NotExistingFile"));
	}
} TEST_END;


TEST(CanParserReadTable__data_test_txt__With4Rows5Columns) {
	void test(){
	  TableWithHeader t = parse(ifstream("data/test.txt"));
	  vector<vector<Element>> &a = t.content;
	  vector<string> &hat = t.hat;
		// a - ��� �������
		// a vvE
		// a.size - ����� �����
		// a[0] vE - ������ ������� �������
		// a[0].size - ����� ������ ������� ������� (����� �������) (������ ��������� �� ����� ����������)
		// a[0][0] - ������ ������� ������ ������ (string ��� �����)

		assertTrue(a.size() == 4); // ����� ����� = 4

		for (size_t i = 0; i < a.size(); ++i)
			assertTrue(a[i].size() == 5); // ����� ������� = 5

		assertEquals(3, (int) a[2][0]);
		assertEquals(string("�������� �������"), (string) a[0][1]);
		assertEquals(string("123"), (string) a[1][3]);
		assertEquals(3, (int) a[3][4]);


		assertEquals(string("id"), hat[0]);
		assertEquals(string("name"), hat[1]);
		assertEquals(string("login"), hat[2]);
		assertEquals(string("password"), hat[3]);
		assertEquals(string("type_id"), hat[4]);
	}
} TEST_END;

