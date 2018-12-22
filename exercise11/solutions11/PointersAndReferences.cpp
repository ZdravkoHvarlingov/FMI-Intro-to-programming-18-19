#include <iostream>

using namespace std;

void Swap(int *fst, int *snd)
{
	int temp = *fst;
	*fst = *snd;
	*snd = temp;
}

void Swap(int &fst, int &snd)
{
	int temp = fst;
	fst = snd;
	snd = temp;
}

void PrintArrayElements(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int Sum(int *start, int *end)
{
	int sum = 0;
	for (int *crr = start; crr != end; ++crr)
	{
		sum += *crr;
	}

	//If we want to include the final element
	//sum += *end;

	return sum;
}

void FindMax(int *arr, int size, int &max)
{
	if (size == 0)
	{
		return;
	}

	if (max < *arr)
	{
		max = *arr;
	}
	FindMax(arr + 1, size - 1, max);
}

int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 5, 4, 3 };

	PrintArrayElements(arr, SIZE);
	
	int max = arr[0];
	FindMax(arr, SIZE, max);
	cout << "Maximum is: " << max << endl;

	cout << "Sum of all except the last is: " << Sum(arr, arr + SIZE - 1) << endl;

    return 0;
}

