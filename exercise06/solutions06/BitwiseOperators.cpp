#include <iostream>

using namespace std;

//pow(2, n)
int CalcPowerOf2(int n)
{
	//This is 2 to the power of 0 --- ....00001 as binary representation
	int result = 1;

	return (result << n);
}

//number * pow(2, n)
int MultiplyWith2toThePowerOfN(int number, int n)
{
	return (number << n);
}

bool IsEven(int number)
{
	return (number & 1) == 0;
}

bool IsOdd(int number)
{
	return (number & 1) == 1;
}

int GetNumberOfZeros(int number)
{
	if (number == 0)
	{
		return -1;
	}

	int index = 0;
	while ((number & 1) == 0)
	{
		//number >>= 1;
		number = number >> 1;

		++index;
	}

	return index;
}

int main()
{
    return 0;
}

