#include <iostream>
#include <algorithm>

using namespace std;

int GetMinimumIndex(int arr[], int size)
{
	if (size <= 0)
	{
		return -1;
	}

	int minInd = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < arr[minInd])
		{
			minInd = i;
		}
	}

	return minInd;
}

int GetMinimumIndex(int arr[], int size, int start)
{
	if (start >= size)
	{
		return -1;
	}

	int minIndex = start;
	for (size_t i = start + 1; i < size; i++)
	{
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

void SwapFirstWithMinimum(int arr[], int size, int start)
{
	int minIndex = GetMinimumIndex(arr, size, start);
	if (minIndex == -1)
	{
		return;
	}

	int temp = arr[minIndex];
	arr[minIndex] = arr[start];
	arr[start] = temp;
}

void SelectionSort(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		SwapFirstWithMinimum(arr, size, i);
	}
	
	//DirectAproach
	/* for(size_t i = 0; i < size - 1; ++i)
	{
		//We want to place the minimum element in arr[i...size - 1] in place arr[i]
		//So we iterate all elements in arr[i + 1...size - 1]
		for(size_t j = 1 + i; j < size; ++j)
		{
			if(numbers[j] < numbers[i])
			{
				swap(numbers[i], numbers[j]);
			}
		}
	} */
}

int main()
{
	const int size = 10;
	int numbers[size];

	for (size_t i = 0; i < size; i++)
	{
		cin >> numbers[i];
	}

	SelectionSort(numbers, size);

	for (size_t i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << '\n';

    return 0;
}

