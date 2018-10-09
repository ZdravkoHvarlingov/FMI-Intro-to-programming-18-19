// 3DigitNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Please enter a 3 digit number: ";

	int number;
	cin >> number;

	int sum = 0;
	sum += number % 10;
	number /= 10;

	sum += number % 10;
	number /= 10;

	sum += number;

	cout << "Result: " << sum << endl;

 	return 0;
}

