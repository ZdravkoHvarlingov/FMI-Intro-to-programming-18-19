#include <iostream>

using namespace std;

//O(n)
long long RegularPow(long long a, long long n)
{
	if (n == 0)
	{
		return 1;
	}

	return a * RegularPow(a, n - 1);
}

//O(logn)
long long FastPow(long long a, long long n)
{
	if (n == 0)
	{
		return 1;
	}

	long long halfPow = FastPow(a, n / 2);
	if (n % 2 == 0)
	{
		return halfPow * halfPow;
	}

	return halfPow * halfPow * a;
}

int main()
{
	cout << FastPow(2, 10) << endl;
	cout << RegularPow(2, 10) << endl;

    return 0;
}

