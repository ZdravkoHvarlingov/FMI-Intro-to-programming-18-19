#include <iostream>

using namespace std;

void HanoiTowers(int n, char from, char to, char swap)
{
	if (n == 0)
	{
		return;
	}

	HanoiTowers(n - 1, from, swap, to);
	cout << "Moving disk from " << from << " to " << to << endl;
	HanoiTowers(n - 1, swap, to, from);
}

int main()
{
	HanoiTowers(3, 'A', 'C', 'B');

    return 0;
}

