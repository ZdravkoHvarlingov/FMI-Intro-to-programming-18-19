#include <iostream>

using namespace std;

int CalcDigitsSum(int number, bool evenOnes)
{
	bool shouldGetDigit = evenOnes ? true : false;

	int result = 0;
	while (number > 0)
	{
		int crrDigit = number % 10;
		if (shouldGetDigit)
		{
			result += crrDigit;
			shouldGetDigit = false;
		}
		else
		{
			shouldGetDigit = true;
		}

		number /= 10;
	}

	return result;
}

int main()
{
	int ivanchoNumber, marijkaNumber, rows;
	cin >> ivanchoNumber >> marijkaNumber >> rows;

	int ivanchoPoints = 0, marijkaPoints = 0;
	for (size_t i = 0; i < rows; i++)
	{
		char identifier;
		int points;

		cin >> identifier >> points;
		if (identifier == 'i')
		{
			ivanchoPoints += points;
		}
		else
		{
			marijkaPoints += points;
		}
	}

	int evenDigitsSum = CalcDigitsSum(marijkaPoints, true);
	int oddDigitsSum = CalcDigitsSum(ivanchoPoints, false);

	if (evenDigitsSum % marijkaNumber == 0 && oddDigitsSum % ivanchoNumber == 0)
	{
		cout << "Tie\n";
	}
	else if (evenDigitsSum % marijkaNumber == 0)
	{
		cout << "Marijka\n";
	}
	else if (oddDigitsSum % ivanchoNumber == 0)
	{
		cout << "Ivancho\n";
	}
	else if (marijkaPoints == ivanchoPoints)
	{
		cout << "Tie\n";
	}
	else if (marijkaPoints > ivanchoPoints)
	{
		cout << "Marijka\n";
	}
	else
	{
		cout << "Ivancho\n";
	}
}