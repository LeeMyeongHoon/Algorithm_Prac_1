// https://algospot.com/judge/problem/read/TRIANGLEPATH 



#ifdef ¿Á±Õ»£√‚
#include <iostream>
#include <algorithm>
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
			for (size_t j = 0; j < i + 1; j++)
			{
				std::cin >> data[i][j];
				history[i][j] = -1;
			}
		}
	}

	size_t GetSum(size_t i, size_t j)
	{
		if (j == size - 1)
		{
			return data[i][j];
		}

		auto& cache = history[i][j];

		if (cache != -1)
		{
			return cache;
		}

		return cache = data[i][j] + std::max(GetSum(i + 1, j), GetSum(i + 1, j + 1));
	}

	void Solve()
	{
		std::cout << GetSum(0, 0) << '\n';
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
#endif // ¿Á±Õ»£√‚
