//memory leaks libraries
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include <iostream>

using namespace std;

void AllocateArray(int n)
{
	if (n < 1)
	{
		return;
	}

	int *arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;
}

int* Concatenate(int *first, int *second, int firstSize, int secondSize)
{
	int resultSize = firstSize + secondSize;
	int *result = new int[resultSize];

	for (size_t i = 0; i < firstSize; i++)
	{
		result[i] = first[i];
	}
	for (size_t i = 0; i < secondSize; i++)
	{
		result[i + firstSize] = second[i];
	}

	return result;
}

int* Sort(int *arr, int size)
{
	int *sorted = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		sorted[i] = arr[i];
	}

	for (size_t i = 1; i < size; i++)
	{
		int j = i - 1;
		int element = sorted[i];
		while (j >= 0 && sorted[j] > element)
		{
			sorted[j + 1] = sorted[j];
			--j;
		}
		sorted[j + 1] = element;
	}

	return sorted;
}

void MakeDynamicMatrix(int rows, int cols)
{
	int **matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	int counter = 1;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = counter++;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int fst[] = { 1, 2, 3 };
	int snd[] = { 4, 5, 6 };
	int *result = Concatenate(snd, fst, 3, 3);
	for (size_t i = 0; i < 6; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	//if not delete - memory leak! :(
	//delete[] result;

	_CrtDumpMemoryLeaks();

    return 0;
}

