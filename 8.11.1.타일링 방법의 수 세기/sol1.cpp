// https://algospot.com/judge/problem/read/TILING2

#include <iostream>
#include <vector>

struct Soluter
{
	size_t width;
	size_t history[101];

	void Input()
	{
		std::cin >> width;
	}

	size_t AllCounting(size_t curWidth)
	{
		if (curWidth <= 1)
		{
			return 1;
		}

		auto& cache = history[curWidth];

		if (cache != -1)
		{
			return cache;
		}

		size_t ret = AllCounting(curWidth - 1) + AllCounting(curWidth - 2);

		if (ret >= 1000000007u)
		{
			ret %= 1000000007u;
		}

		return cache = ret;
	}

	void Solve()
	{
		for (auto& history0 : history)
		{
			history0 = -1;
		}

		std::cout << AllCounting(width) << '\n';
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