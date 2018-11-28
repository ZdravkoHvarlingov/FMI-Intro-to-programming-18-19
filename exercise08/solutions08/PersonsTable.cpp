#include <iostream>
#include <cstring>

using namespace std;

#define FIRST_NAME 0
#define FAMILY_NAME 1
#define AGE 2
#define CITY 3
#define IS_STUDENT 4

int CharArrayToInt(char number[256])
{
	int result = 0, currentMultiplier = 1;
	int numberLength = strlen(number);
	for (int i = numberLength - 1; i >= 0; i--)
	{
		result += currentMultiplier * (number[i] - '0');
		currentMultiplier *= 10;
	}

	return result;
}

int GetNumberOfPeopleIn(const char city[256], char persons[100][5][256], int n)
{
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(city, persons[i][CITY]) == 0)
		{
			++count;
		}
	}

	return count;
}

double GetAverageAge(char persons[100][5][256], int n)
{
	double result = 0;
	for (size_t i = 0; i < n; i++)
	{
		result += CharArrayToInt(persons[i][AGE]);
	}

	return result / n;
}

void ChangePersonCity(const char firstName[256], const char familyName[256], 
	const char newCity[256], char persons[100][5][256], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(firstName, persons[i][FIRST_NAME]) == 0 && strcmp(familyName, persons[i][FAMILY_NAME]) == 0)
		{
			strcpy(persons[i][CITY], newCity);
		}
	}
}

char ToLower(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
	{
		return 'a' + (symbol - 'A');
	}

	return symbol;
}

void PrintStudentsWithNameStartingWith(char symbol, char persons[100][5][256], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (ToLower(persons[i][FIRST_NAME][0]) == ToLower(symbol) && strcmp(persons[i][IS_STUDENT], "Yes") == 0)
		{
			cout << persons[i][FIRST_NAME] << " " << persons[i][FAMILY_NAME] << " " << persons[i][AGE] << " ";
			cout << persons[i][CITY] << " " << persons[i][IS_STUDENT] << endl;
		}
	}
}

bool IsFirstNameEqualToReversedFamilyName(const char firstName[256], const char familyName[256])
{
	if (strlen(firstName) != strlen(familyName))
	{
		return false;
	}

	int length = strlen(firstName);
	for (size_t i = 0; i < length; i++)
	{
		if (ToLower(firstName[i]) != ToLower(familyName[length - 1 - i]))
		{
			return false;
		}
	}

	return true;
}

void PrintPeopleWithFirstNameEqualToReversedFamilyName(char persons[100][5][256], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (IsFirstNameEqualToReversedFamilyName(persons[i][FIRST_NAME], persons[i][FAMILY_NAME]))
		{
			cout << persons[i][FIRST_NAME] << " " << persons[i][FAMILY_NAME] << " " << persons[i][AGE] << " ";
			cout << persons[i][CITY] << " " << persons[i][IS_STUDENT] << endl;
		}
	}
}

void PrintTable(char persons[100][5][256], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << persons[i][FIRST_NAME] << " " << persons[i][FAMILY_NAME] << " " << persons[i][AGE] << " ";
		cout << persons[i][CITY] << " " << persons[i][IS_STUDENT] << endl;	
	}
}

int main()
{
	char name[100] = "Kiro";
	char persons[100][5][256];
	int n;
	cin >> n;
	//Filling the table with information
	for (size_t i = 0; i < n; i++)
	{
		for (size_t col = 0; col < 5; col++)
		{
			cin >> persons[i][col];
		}
	}

	cout << GetAverageAge(persons, n) << endl;
}