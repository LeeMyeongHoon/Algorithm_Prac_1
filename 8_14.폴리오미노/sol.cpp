// https://algospot.com/judge/problem/read/POLY

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	size_t AllBlockCount;
	size_t history[100][100];

	void Input()
	{
		std::cin >> AllBlockCount;
	}

	void Solve()
	{
		for (auto& history1 : history)
		{
			for (auto& history2 : history1)
			{
				history2 = -1;
			}
		}

		size_t count = 0;
		for (size_t firstBlockCount = 1; firstBlockCount <= AllBlockCount; firstBlockCount++)
		{
			count += GetCount(firstBlockCount, AllBlockCount - firstBlockCount);
			if (count >= 10000000)
			{
				count %= 10000000;
			}
		}

		std::cout << count << '\n';
	}

	size_t GetCount(size_t prevBlockCount, size_t useableBlockCount)
	{
		if (useableBlockCount == 0)
		{
			return 1;
		}

		auto& cache = history[prevBlockCount][useableBlockCount];

		if (cache != -1)
		{
			return cache;
		}


		cache = 0;
		for (size_t newBlockCount = 1; newBlockCount <= useableBlockCount; newBlockCount++)
		{
			cache += (prevBlockCount + newBlockCount - 1) * GetCount(newBlockCount, useableBlockCount - newBlockCount);
			if (cache >= 10000000)
			{
				cache %= 10000000;
			}
		}

		return cache;
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