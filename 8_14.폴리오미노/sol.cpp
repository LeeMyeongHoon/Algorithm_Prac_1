// https://algospot.com/judge/problem/read/POLY

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int AllBlockCount;
	int history[100][100];

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

		int count = 0;
		for (int firstBlockCount = 1; firstBlockCount <= AllBlockCount; firstBlockCount++)
		{
			count += GetCount(firstBlockCount, AllBlockCount - firstBlockCount);
			if (count >= 10000000)
			{
				count %= 10000000;
			}
		}

		std::cout << count << '\n';
	}

	int GetCount(int prevBlockCount, int useableBlockCount)
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
		for (int newBlockCount = 1; newBlockCount <= useableBlockCount; newBlockCount++)
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

int main()
{
	int count;
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