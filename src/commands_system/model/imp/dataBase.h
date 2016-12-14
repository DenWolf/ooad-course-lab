#pragma once

// ���� ������
#include "../../db/IDataBase.h"

// ������� ��� ������
#include "../../db/DataBaseException.h"




// ���������� ��� ���������� ������� �������
#include "../../db/ITable.h"
// ��� ��������
#include <memory>
class ptrTable : public std::unique_ptr<const ITable> {
public:
	ptrTable(const ITable *p) : std::unique_ptr<const ITable>(p) {}
};




// ������� ������� �� ��������� (���� int, ���� string)
#include "../../db/Element.h"

// ������� ��� ������������ �����
#include "../../db/WrongTypeException.h"





// �������

// ���� ������ Select'� (��� get* �������)
#include "../../db/Select.h"
// ��� ��������
#define SELECT(columns) (Select(std::vector<std::string>((columns), &(columns)[sizeof(columns)/sizeof(*(columns))])))
#define SELECT_ONLY(one_column) (Select(std::vector<std::string>(1, one_column)))

#include "../../db/Update.h"
#define SET_ONLY(column, value) set(std::vector<std::pair<std::string, Element> >(1, std::pair<std::string, Element>((column), (value))))






// ��������� ���� ������ (��������� ������� ����� ����)
#include "../../db/instance.h"

