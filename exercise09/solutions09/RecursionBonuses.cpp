#include <iostream>

using namespace std;

void ConvertToBinary(unsigned int number)
{
	if (number == 0)
	{
		return;
	}

	ConvertToBinary(number / 2);
	cout << number % 2;
}

char GetDigit(int number)
{
	if (number <= 9)
	{
		return '0' + number;
	}

	number -= 10;
	return 'A' + number;
}

void ConvertToHexaDecimal(unsigned int number)
{
	if (number == 0)
	{
		return;
	}

	ConvertToHexaDecimal(number / 16);
	cout << GetDigit(number % 16);
}

int main()
{
	ConvertToHexaDecimal(1234);
	cout << endl;

    return 0;
}

