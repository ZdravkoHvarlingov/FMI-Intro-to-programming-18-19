#include <iostream>

using namespace std;

int main()
{
	int N1, N2, N3;
	cin >> N1 >> N2 >> N3;

	int ***arr = new int**[N1];
	for (int i = 0; i < N1; ++i)
	{
		arr[i] = new int*[N2];
		for (int j = 0; j < N2; ++j)
		{
			arr[i][j] = new int[N3];
		}
	}
	cout << "GG, I created it!" << endl;
	for (int i = 0; i < N1; i++)
	{
		for (int j = 0; j < N2; j++)
		{
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}

	delete[] arr;

    return 0;
}

