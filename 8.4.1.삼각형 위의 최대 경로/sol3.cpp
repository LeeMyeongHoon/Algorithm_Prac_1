// https://algospot.com/judge/problem/read/TRIANGLEPATH 

// #define ¹è¿­
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

struct Soluter
{
	size_t size;
	size_t str[100][100];
	size_t history[100][100];

	void Input()
	{
		std::cin >> size;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < i + 1; j++)
			{
				std::cin >> str[i][j];
			}
		}
	}

	void Solve()
	{
		//FindMax();
		history[0][0] = str[0][0];
		for (size_t i = 1; i < size; i++)
		{
			for (size_t j = 0; j < i + 1; j++)
			{
				if (j == 0)
				{
					history[i][j] = history[i - 1][j] + str[i][j];
				}

				else
				{
					history[i][j] = std::max(history[i - 1][j - 1] + str[i][j], history[i - 1][j] + str[i][j]);
				}
			}
		}

		size_t max = -1;
		for (size_t j = 0; j < size; j++)
		{
			if (max < history[size - 1][j])
			{
				max = history[size - 1][j];
			}
		}

		std::cout << max << '\n';
	}
};

size_t main()
{
	size_t count;
	std::cin >> count;

	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}

	return 0;
}
