#include <iostream>
#include <vector>
#include <algorithm>

const char BLOCK = '#';
const char EMPTY = '.';

struct Soluter
{
	char data[5][5];
	static int history[33554432];

	void Input()
	{
		for (int i = 0; i < 5; i++)
		{
			std::cin >> data[i];
		}
	}

	int GetBinaryState(char** data)
	{
		int binary = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				binary *= 2;
				if (data[i][j] == BLOCK)
				{
					binary += 1;
				}
				/*else
				{
					binary += 0;
				}*/
			}
		}
		return binary;
	}

	bool CanWin()
	{
		if (true)
		{

		}
	}

	void Solve()
	{
		/*for (auto& cache : history)
		{
			cache = -1;
		}*/
	}
};