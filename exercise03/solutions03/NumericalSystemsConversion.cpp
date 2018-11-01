// NumericalSystemsConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int ConvertKBaseToDecimal(int number, int k)
{
	int multiplier = 1; //k to the power of 0
	int result = 0;

	while (number > 0)
	{
		int crrDigit = number % 10;
		result += crrDigit * multiplier;

		multiplier *= k;
		number /= 10;
	}

	return result;
}

int ConvertDecimalToKBase(int number, int k)
{
	int result = 0;
	int multiplier = 1;

	while (number > 0)
	{
		int crrRemainder = number % k;
		result += crrRemainder * multiplier;
		multiplier *= 10;

		number /= k;
	}

	return result;
}

int main()
{
	int number;
	cin >> number;

	cout << ConvertDecimalToKBase(number, 8) << '\n';

    return 0;
}

