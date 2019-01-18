#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	char **fileNames = new char*[N];
	for (size_t i = 0; i < N; i++)
	{
		fileNames[i] = new char[128];
	}

	for (size_t i = 0; i < N; i++)
	{
		cin >> fileNames[i];
	}
	char result[128];
	cin >> result;
	ofstream resultFile(result);
	for (size_t i = 0; i < N; i++)
	{
		ifstream crrFile(fileNames[i]);
		char line[1024];
		while (crrFile.getline(line, 1024))
		{
			int length = strlen(line);
			line[length] = '\n';
			resultFile.write(line, length + 1);
		}
		crrFile.close();
	}
	resultFile.close();

	for (size_t i = 0; i < N; i++)
	{
		delete[] fileNames[i];
	}
	delete[] fileNames;

    return 0;
}

