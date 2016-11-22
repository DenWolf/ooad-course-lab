#pragma once

#include "../utils/Exception.h"


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

