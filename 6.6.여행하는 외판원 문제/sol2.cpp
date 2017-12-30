// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <limits>
#include <algorithm>

struct Soluter
{
	using City = size_t;

	size_t cityCount;
	bool isVisited[10] = { false };
	size_t cost[10][10];
	size_t minTotalCost = std::numeric_limits<size_t>::max();


	void Input()
	{
		std::cin >> cityCount;

		for (size_t i = 0; i < cityCount; i++)
		{
			for (size_t j = 0; j < cityCount; j++)
			{
				std::cin >> cost[i][j];
			}
		}
	}

	void SetMinTotalCost(City beginCity, City curCity, size_t curTotalCost, size_t visitCount)
	{
		if (curTotalCost >= minTotalCost)
		{
			return;
		}
		if (visitCount == cityCount && cost[curCity][beginCity] != 0)
		{
			minTotalCost = std::min(minTotalCost, curTotalCost + cost[curCity][beginCity]);
			return;
		}
		for (City dstCity = 0; dstCity < cityCount; dstCity++)
		{
			if (!isVisited[dstCity] && cost[curCity][dstCity] != 0)
			{
				isVisited[dstCity] = true;
				SetMinTotalCost(beginCity, dstCity, curTotalCost + cost[curCity][dstCity], visitCount + 1);
				isVisited[dstCity] = false;
			}
		}
	}

	void Solve()
	{
		for (City beginCity = 0; beginCity < cityCount; beginCity++)
		{
			isVisited[beginCity] = true;
			SetMinTotalCost(beginCity, beginCity, 0, 1);
			isVisited[beginCity] = false;
		}

		std::cout << minTotalCost << '\n';
	}
};

size_t main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}