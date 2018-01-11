// https://www.acmicpc.net/problem/1149
// Àç±ÍÀû DP
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Soluter
{
	static const int COLOR_COUNT = 3;

	int houseCount;
	int costs[1001][COLOR_COUNT];
	int history[COLOR_COUNT][1001];

	void Input()
	{
		std::cin >> houseCount;
		for (int house = 0; house < houseCount; house++)
		{
			for (int color = 0; color < COLOR_COUNT; color++)
			{
				std::cin >> costs[house][color];
			}
		}
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

		int minCost = std::numeric_limits<int>::max();
		for (int firstColor = 0; firstColor < COLOR_COUNT; firstColor++)
		{
			minCost = std::min(minCost, costs[0][firstColor] + GetMinCost(firstColor, 1));
		}

		std::cout << minCost << '\n';
	}

	int GetMinCost(int prevColor, int curHouse)
	{
		if (curHouse == houseCount)
		{
			return 0;
		}

		auto& cache = history[prevColor][curHouse];

		if (cache != -1)
		{
			return cache;
		}

		int minCost = std::numeric_limits<int>::max();

		for (int color = 0; color < COLOR_COUNT; color++)
		{
			if (color != prevColor)
			{
				minCost = std::min(minCost, costs[curHouse][color] + GetMinCost(color, curHouse + 1));
			}
		}


		return cache = minCost;
	}

};

int main()
{
	Soluter soluter;

	soluter.Input();

	soluter.Solve();

	return 0;
}
