// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int number;
	double sum = 0;

	cout << "Enter a number: ";
	cin >> number;
	sum += number;

	cout << "Enter a number: ";
	cin >> number;
	sum += number;

	cout << "Enter a number: ";
	cin >> number;
	sum += number;

	cout << "Enter a number: ";
	cin >> number;
	sum += number;

	cout << "Enter a number: ";
	cin >> number;
	sum += number;

	cout << "Average: " << sum / 5 << endl;
    return 0;
}

