// PrintTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintNSymbols(int n, char symbol)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << symbol;
	}
}

void PrintSteps(int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		PrintNSymbols(i + 1, '*');
		cout << '\n';
	}
}

void PrintReverseSteps(int rows)
{
	for (size_t i = 1; i <= rows; i++)
	{
		PrintNSymbols(rows - i, ' ');
		PrintNSymbols(i, '*');
		cout << '\n';
	}
}

void PrintTree(int rows)
{
	for (size_t i = 1; i <= rows; i++)
	{
		PrintNSymbols(rows - i, ' ');
		PrintNSymbols(i * 2, '*');
		cout << '\n';
	}
}

//rows should be even
void PrintDiamond(int rows)
{
	rows /= 2;
	for (size_t i = 1; i <= rows; i++)
	{
		PrintNSymbols(rows - i, ' ');
		PrintNSymbols(i * 2, '*');
		cout << '\n';
	}
	for (size_t i = 0; i < rows; i++)
	{
		PrintNSymbols(i, ' ');
		PrintNSymbols((rows - i) * 2, '*');
		cout << '\n';
	}
}

int main()
{
	int n;
	cin >> n;
	
	PrintDiamond(n);

    return 0;
}

