#include <iostream>

#define N 8
int bitset[N];

void PrintIt()
{
	for (size_t i = 0; i < N; i++)
	{
		std::cout << bitset[i] << " ";
	}
	std::cout << '\n';
}

void GenerateAll(int ind)
{
	if (ind == N)
	{
		PrintIt();
		return;
	}

	bitset[ind] = 0;
	GenerateAll(ind + 1);
	bitset[ind] = 1;
	GenerateAll(ind + 1);
}

int main()

{
	GenerateAll(0);
}

