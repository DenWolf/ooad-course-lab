#pragma once

#include "../utils/Exception.h"
#include <string>


//����������:
//	������������ ��� ���������/������� �������� � �������� ���� ������.
//�������������:
//	����� �������� ������� ���� ����� ������.
//	��� ���������� �������� � ������ �������������� ����� ������� WrongTypeException.
//��������:
//	=(const &)
//	=(&&)
//	const & != const &
class Element {
private:
	// virtual function table
	const struct _Element_vft *__vft;

protected:
	union {
		int integer;
		char *str;
	} data;

	Element() {}

public:
	Element(int integer);
	Element(const char *string);
	Element(const std::string &string);

//virtual:
	Element(const Element &);
	Element(Element &&);

	operator int() const;
	operator std::string() const;
	~Element();

	friend bool operator ==(const Element &a, const Element &b);
};



bool operator ==(const Element &a, const Element &b);

// needed because of operator ==(int, int)
bool operator ==(const Element &a, int i);
bool operator ==(int i, const Element &a);




//����������:
//	��������� ��� �������������� ����� ������ � ������� ������ Element:
//	- ���������� � ������: operator int;
//	- ���������� � ������: operator string;
//	- ���������: operator ==.
//�������������:
//	Element e = 100;
//	try {
//		int i = e; // OK
//		string s = e; // throw WrongTypeException
//	} catch (WrongTypeException e) {
//		std::cerr << e.what(); // "Element doesn't contain <string>"
//	}
class WrongTypeException : public Exception {
public:
	WrongTypeException(const char *what) : Exception(what) {}
};

