#include <iostream>

using namespace std;

struct Test1
{
	char symbol1;
	int num;
	char symbol2;
};

struct Test2
{
	char symbol1;
	char symbol2;
	int num;
};

struct Test3
{
	int num;
	char symbol1;
	char symbol2;
};

struct Test4
{
	char symbols[3];
	int num;
	double decimalNum;
};

struct Test5
{
	double decimalNum;
	int num;
	char symbols[3];
};

struct Test6
{
	char symbols[3];
	int num;
	char badSymbol;
	double decimalNum;
	char final;
};

struct Test7
{
	char symbols[3];
	char badSymbol;
	char final;
	int num;
	double decimalNum;
};

struct Test8
{
	double decimalNum;
	int num;
	char symbols[3];
	char badSymbol;
	char final;
};

struct Datetime
{
	int month;
	int day;
	int hour;
	int minute;
};

struct EmailInfo
{
	Datetime sendingTime;
	char sender[128];
	char recipient[128];
};

int main()
{
	cout << sizeof(Test1) << endl;
	cout << sizeof(Test2) << endl;
	cout << sizeof(Test3) << endl;
	cout << sizeof(Test4) << endl;
	cout << sizeof(Test5) << endl;
	cout << sizeof(Test6) << endl;
	cout << sizeof(Test7) << endl;
	cout << sizeof(Test8) << endl;

	cout << sizeof(EmailInfo) << endl;

    return 0;
}

