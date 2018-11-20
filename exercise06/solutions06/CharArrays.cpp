#include <iostream>
#include <cstring>

using namespace std;

bool IsSmallLetter(char letter)
{
	return letter >= 'a' && letter <= 'z';
}

bool IsCapitalLetter(char letter)
{
	return letter >= 'A' && letter <= 'Z';
}

//Task 1
void SwapCapitalWithSmallLetters(char text[])
{
	int textLength = strlen(text);
	
	for(int i = 0; i < textLength; ++i)
	{
		if(IsSmallLetter(text[i]))
		{
			text[i] = (text[i] - 'a') + 'A';
		}
		else if(IsCapitalLetter(text[i]))
		{
			text[i] = (text[i] - 'A') + 'a';
		}
	}
}

bool DoesStartWith(char text[], int start, char subText[])
{
	int firstLength = strlen(text);
	int secondLength = strlen(subText);

	if (secondLength > firstLength - start)
	{
		return false;
	}

	for (size_t i = 0; i < secondLength; i++)
	{
		if (text[start + i] != subText[i])
		{
			return false;
		}
	}

	return true;
}

//Task 2
bool DoesContain(char text[], char subText[])
{
	int textLength = strlen(text);
	for (size_t i = 0; i < textLength; i++)
	{
		bool contains = DoesStartWith(text, i, subText);
		if (contains)
		{
			return true;
		}
	}

	return false;
}

//Bonus Task 1
int GetEnglishAlphabetStart(char text[])
{
	int textLength = strlen(text);
	char alphabet[27];
	for (size_t i = 0; i < 26; i++)
	{
		alphabet[i] = 'a' + i;
	}
	alphabet[26] = '\0';

	for (size_t i = 0; i < textLength; i++)
	{
		if (DoesStartWith(text, i, alphabet))
		{
			return i;
		}
	}

	return -1;
}

bool IsAlphabetPermutation(char text[], int start)
{
	int textLength = strlen(text);
	if (textLength - start < 26)
	{
		return false;
	}

	bool alphabets[26] = { false };
	for (size_t i = start; i < start + 26; i++)
	{
		if (text[i] - 'a' >= 0 && text[i] - 'a' < 26)
		{
			alphabets[text[i] - 'a'] = true;
		}
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (alphabets[i] == false)
		{
			return false;
		}
	}

	return true;
}

//Bonus Task 1
int GetEnglishAlphabetPermutationStart(char text[])
{
	int textLength = strlen(text);

	for (size_t i = 0; i < textLength; i++)
	{
		if (IsAlphabetPermutation(text, i))
		{
			return i;
		}
	}

	return -1;
}

bool IsSmallLetter(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

//Task 2 - faster implementation
int GetAlphabetStartFaster(char text[])
{
	int textLength = strlen(text);
	int letterCounter[26] = { 0 };
	int uniqueLettersCount = 0;

	for (int i = 0; i < textLength; i++)
	{
		if (IsSmallLetter(text[i]))
		{
			++letterCounter[text[i] - 'a'];
			if (letterCounter[text[i] - 'a'] == 1)
			{
				++uniqueLettersCount;
			}
		}
		if (i - 26 >= 0 && IsSmallLetter(text[i - 26]))
		{
			--letterCounter[text[i - 26] - 'a'];
			if (letterCounter[text[i - 26] - 'a'] == 0)
			{
				--uniqueLettersCount;
			}
		}

		if (uniqueLettersCount == 26)
		{
			return i - 25;
		}
	}

	return -1;
}

//Bonus Task 3
void PrintOccurences(char text[])
{
	int textLength = strlen(text);

	for (size_t i = 0; i < textLength; i++)
	{
		int minIndex = i;
		for (size_t j = i + 1; j < textLength; j++)
		{
			if (text[j] < text[minIndex])
			{
				minIndex = j;
			}
		}
		swap(text[minIndex], text[i]);
	}

	int counter = 1;
	for (size_t i = 1; i < textLength; i++)
	{
		if (text[i] != text[i - 1])
		{
			cout << text[i - 1] << '-' << counter << '\n';
			counter = 1;
		}
		else
		{
			++counter;
		}
	}
	cout << text[textLength - 1] << '-' << counter << '\n';
}

int main()
{
	char text[100];
	cin >> text;

	cout << GetEnglishAlphabetPermutationStart(text) << '\n';
	cout << GetAlphabetStartFaster(text) << '\n';
	PrintOccurences(text);
}