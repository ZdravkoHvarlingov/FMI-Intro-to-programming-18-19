#include <iostream>

using namespace std;

int GetNthFibonacci(int n)
{
	int previous = 0, current = 1;
	
	for (size_t i = 0; i < n - 1; i++)
	{
		int oldPrevious = previous;
		previous = current;
		current = current + oldPrevious;
	}

	return previous;
}

int main()
{
	int n;
	cin >> n;

	cout << GetNthFibonacci(n) << '\n';
}