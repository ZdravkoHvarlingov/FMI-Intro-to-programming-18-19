#include <iostream>

using namespace std;

long long ReverseNumber(long long number)
{
	long long reversedNumber = 0;

	while (number > 0)
	{
		reversedNumber *= 10;
		reversedNumber += number % 10;

		number /= 10;
	}

	return reversedNumber;
}

bool IsPalindromNumber(long long number)
{
	return number == ReverseNumber(number);
}

int main()
{
	long long number;
	cin >> number;

	cout << IsPalindromNumber(number) << '\n';
}