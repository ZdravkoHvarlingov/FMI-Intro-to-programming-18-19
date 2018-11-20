#include <iostream>

using namespace std;

void RotateRight(int arr[], int size)
{
	if (size == 0)
	{
		return;
	}

	int last = arr[size - 1];
	for (size_t i = size - 1; i >= 1; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = last;
}

void RotateLeft(int arr[], int size)
{
	if (size == 0)
	{
		return;
	}

	int first = arr[0];
	for (size_t i = 0; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	arr[size - 1] = first;
}

void PrintArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void InputArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	int n;
	cin >> n;
	
	const int m = 10;
	int arr[m];
	InputArray(arr, m);

	PrintArray(arr, m);
	for (size_t i = 0; i < n; i++)
	{
		RotateLeft(arr, m);
		PrintArray(arr, m);
	}

    return 0;
}

