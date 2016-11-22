#pragma once

#include <string>


//����������:
//	������������ ��� ���������/������� �������� � �������� ���� ������.
//�������������:
//	����� �������� ������� ���� ����� ������.
//	��� ���������� �������� � ������ �������������� ����� ������� WrongTypeException.
class Element {
private:
	// virtual function table
	const struct _Element_vft *__vft;

protected:
	union {
		int integer;
		char *str;
	} data;


public:
	Element();
	Element(int integer);
	Element(const char *string);
	Element(const std::string &string);

//virtual:
	Element(const Element &);
	Element(Element &&);

	operator int() const;
	operator std::string() const;
	~Element();

	Element & operator =(const Element &);
	Element & operator =(Element &&);

	bool equals(const Element &) const;

private:
	// �� ������������:
	void operator +=(const Element &);
	void operator -=(const Element &);
	void operator *=(const Element &);
	void operator /=(const Element &);
	void operator %=(const Element &);
	void operator &=(const Element &);
	void operator |=(const Element &);
	void operator ^=(const Element &);
	void operator <<=(int);
	void operator >>=(int);
};


//� ������ ������������ ����� ������� WrongTypeException
bool operator ==(const Element &, const Element &);



// �� ������������:
void operator !=(const Element &, const Element &);
void operator >=(const Element &, const Element &);
void operator >(const Element &, const Element &);
void operator <=(const Element &, const Element &);
void operator <(const Element &, const Element &);

void operator +(const Element &);
void operator -(const Element &);
void operator +(const Element &, const Element &);
void operator -(const Element &, const Element &);

void operator *(const Element &, const Element &);
void operator /(const Element &, const Element &);
void operator %(const Element &, const Element &);

void operator ~(const Element &);
void operator ^(const Element &, const Element &);
void operator &(const Element &, const Element &);
void operator |(const Element &, const Element &);
void operator <<(const Element &, int);
void operator >>(const Element &, int);

void operator !(const Element &);
void operator &&(const Element &, const Element &);
void operator ||(const Element &, const Element &);

void operator ++(const Element &);
void operator --(const Element &);
void operator ++(const Element &, int);
void operator --(const Element &, int);

