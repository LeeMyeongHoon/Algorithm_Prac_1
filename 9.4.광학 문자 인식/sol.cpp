#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string words[500];
std::string sentenses[100][5];

double prbFirst[500];
double prbNext[500][500];
double prbIdeti[500][500];

struct Soluter
{
	int wordCount;
	int sentenseCount;


	void Input()
	{
		std::cin >> wordCount >> sentenseCount;

		for (int i = 0; i < wordCount; i++)
		{
			std::cin >> words[i];
		}

		for (int front = 0; front < wordCount; front++)
		{
			for (int back = 0; back < wordCount; back++)
			{
				std::cin >> prbNext[front][back];
			}
		}

		for (int src = 0; src < wordCount; src++)
		{
			for (int dst = 0; dst < wordCount; dst++)
			{
				std::cin >> prbIdeti[src][dst];
			}
		}

		for (int i = 0; i < sentenseCount; i++)
		{
			int wordCount;
			std::cin >> wordCount;
			for (int j = 0; j < wordCount; j++)
			{
				std::cin >> sentenses[i][j];
			}
		}
	}

	void Solve()
	{
		
	}

	double FindMaxPrb()
	{

	}
};