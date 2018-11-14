#include <iostream>

using namespace std;

int GetLength(char text[])
{
	int ind = 0;
	while (text[ind] != '\0')
	{
		++ind;
	}

	return ind;
}

// returns 0 if equal, 
// -1, if first < second
// 1, if first > second
int Compare(char first[], char second[])
{
	int ind = 0;
	while (first[ind] != '\0' && second[ind] != '\0')
	{
		if (first[ind] < second[ind])
		{
			return -1;
		}
		if (first[ind] > second[ind])
		{
			return 1;
		}

		++ind;
	}

	if (second[ind] != '\0')
	{
		return -1;
	}

	if (first[ind] != '\0')
	{
		return 1;
	}

	return 0;
}

void Copy(char source[], char destination[])
{
	int index = 0;
	while (source[index] != '\0')
	{
		destination[index] = source[index];

		++index;
	}

	destination[index] = '\0';
}

int main()
{
	char firstWord[255];
	char secondWord[255];

	cin >> firstWord >> secondWord;
	cout << GetLength(firstWord) << " " << firstWord << endl << GetLength(secondWord) << " " << secondWord << endl;

	Copy(firstWord, secondWord);
	cout << GetLength(firstWord) << " " << firstWord << endl << GetLength(secondWord) << " " << secondWord << endl;

	return 0;
}