#include "../IDataBase.h"
#include <fstream>
#include <string>
#include <unordered_map>


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

#ifdef COMPILE_WITH_TESTS
	void __add_table_test();
#endif

	DataBase();
	std::fstream & getTableFile(const std::string &name_of_table);
	void clearTableFile(const std::string &name_of_table);
};

