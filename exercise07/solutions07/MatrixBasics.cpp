#include <iostream>
#include <algorithm>

using namespace std;

void PrintMatrix(int squareMatrix[10][10])
{
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < 10; col++)
		{
			cout << squareMatrix[row][col] << " ";
		}
		cout << endl;
	}
}

void InputMatrix(int squareMatrix[10][10])
{
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < 10; col++)
		{
			cin >> squareMatrix[row][col];
		}
	}
}

void PrintDiagonal(int squareMatrix[10][10])
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << squareMatrix[i][i] << " ";
	}
	cout << endl;
}

void PrintReverseDiagonal(int squareMatrix[10][10])
{
	//squareMatrix[0][9]
	//squareMatrix[1][8]
	//squareMatrix[2][7]
	//...
	//squareMatrix[9][0]

	for (size_t i = 0; i < 10; i++)
	{
		cout << squareMatrix[i][9 - i] << " ";
	}
	cout << endl;
}

int SumOfElementsUnderDiagonal(int squareMatrix[10][10])
{
	int sum = 0;
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < row; col++)
		{
			sum += squareMatrix[row][col];
		}
	}

	return sum;
}

void RegularFill(int squareMatrix[10][10])
{
	int cellValue = 1;
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < 10; col++)
		{
			squareMatrix[row][col] = cellValue;
			++cellValue;
		}
	}
}

void RightLeftFill(int squareMatrix[10][10])
{
	int cellValue = 1;
	bool fillRight = true;

	for (size_t row = 0; row < 10; row++)
	{
		if (fillRight)
		{
			for (size_t col = 0; col < 10; col++)
			{
				squareMatrix[row][col] = cellValue;
				++cellValue;
			}

			fillRight = false;
		}
		else
		{
			for (size_t col = 9; col >= 0; --col)
			{
				squareMatrix[row][col] = cellValue;
				++cellValue;
			}

			fillRight = true;
		}
	}
}

void TransposeMatrix(int squareMatrix[10][10])
{
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = row; col < 10; col++)
		{
			swap(squareMatrix[row][col], squareMatrix[col][row]);
		}
	}
}

void FillSpiral(int squareMatrix[10][10])
{
	bool isFilled[10][10];
	for (size_t row = 0; row < 10; row++)
	{
		for (size_t col = 0; col < 10; col++)
		{
			isFilled[row][col] = false;
		}
	}

	char direction = 'r';
	int row = 0;
	int col = 0;
	for (size_t i = 1; i <= 10 * 10; i++)
	{
		if (direction == 'r' && (col >= 10 || isFilled[row][col]))
		{
			--col;
			++row;
			direction = 'd';
		}
		else if (direction == 'd' && (row >= 10 || isFilled[row][col]))
		{
			--row;
			--col;
			direction = 'l';
		}
		else if (direction == 'l' && (col < 0 || isFilled[row][col]))
		{
			++col;
			--row;
			direction = 'u';
		}
		else if (direction == 'u' && (row < 0 || isFilled[row][col]))
		{
			++row;
			++col;
			direction = 'r';
		}

		squareMatrix[row][col] = i;
		isFilled[row][col] = true;

		if (direction == 'r')
		{
			++col;
		}
		else if (direction == 'l')
		{
			--col;
		}
		else if (direction == 'u')
		{
			--row;
		}
		else if (direction == 'd')
		{
			++row;
		}
	}
}

int main()
{
	int squareMatrix[10][10];

	FillSpiral(squareMatrix);
	PrintMatrix(squareMatrix);
}