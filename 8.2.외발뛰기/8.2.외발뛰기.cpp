// https://algospot.com/judge/problem/read/JUMPGAME

#include <iostream>
#include <vector>

struct Soluter
{
	size_t size;
	size_t data[100][100];
	size_t history[100][100];

	void Input()
	{
		std::cin >> size;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				history[i][j] = -1;
				std::cin >> data[i][j];
			}
		}
	}

	bool Counting(size_t i, size_t j)
	{
		if (i >= size || j >= size)
		{
			return 0;
		}
		if (data[i][j] == 0)
		{
			return true;
		}
		if (history[i][j] != -1)
		{
			return history[i][j];
		}

		return history[i][j] = Counting(i + data[i][j], j) || Counting(i, j + data[i][j]);
	}

	void Solve()
	{
		if (Counting(0, 0) == true)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
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