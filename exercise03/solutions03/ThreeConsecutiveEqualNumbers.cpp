#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	bool found = false;
	int first, second, third;
	cin >> second >> third;
	for (size_t i = 2; i < n; i++)
	{
		first = second;
		second = third;
		
		cin >> third;

		if (first == second && second == third)
		{
			found = true;
		}
	}

	if (found)
	{
		cout << "There are 3 equal consecutive numbers!\n";
	}
	else
	{
		cout << "There are NOT 3 equal consecutive numbers!\n";
	}
}