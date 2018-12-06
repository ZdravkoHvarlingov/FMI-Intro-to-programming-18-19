#include <iostream>
#include <limits>

using namespace std;

void Print1ToN(int n)
{
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	//Let's print first n - 1 numbers
	Print1ToN(n - 1);
	//And then just print the last one
	cout << n << endl;
}

void PrintNTo1(int n)
{
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	//Print the first number
	cout << n << endl;
	//And then just print the rest
	PrintNTo1(n - 1);
}

int Sum1ToN(int n)
{
	if (n == 1)
	{
		return 1;
	}

	return n + Sum1ToN(n - 1);
}

int SumEven1ToN(int n)
{
	if (n <= 1)
	{
		return 0;
	}

	if (n % 2 != 0)
	{
		return SumEven1ToN(n - 1);
	}

	return n + SumEven1ToN(n - 2);
}

int Pow2(int n)
{
	if (n == 0)
	{
		return 1;
	}

	//2 * 2^(n-1)
	return 2 * Pow2(n - 1);
}

int Pow(int k, int n)
{
	if (n == 0)
	{
		return 1;
	}

	return k * Pow(k, n - 1);
}

int GetMin(int arr[], int size, int ind)
{
	if (ind >= size)
	{
		return INT_MAX;
	}

	//The minimum of the arr[ind + 1...size]
	int nextPartMin = GetMin(arr, size, ind + 1);
	if (arr[ind] < nextPartMin)
	{
		return arr[ind];
	}

	return nextPartMin;
}

int main()
{
	int arr[] = { -1, 1, 3, -5, 10 };
	cout << GetMin(arr, 5, 0) << endl;

    return 0;
}

