// https://www.acmicpc.net/problem/1149
// 반복적 동적계획법
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Soluter
{
	static const int COLOR_COUNT = 3;

	int houseCount;
	int costs[1001][COLOR_COUNT];
	int caches[1001][COLOR_COUNT];

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
		int lastHouse = houseCount - 1;

		for (int prevColor = 0; prevColor < COLOR_COUNT; prevColor++)
		{
			int result = std::numeric_limits<int>::max();
			for (int curColor = 0; curColor < COLOR_COUNT; curColor++)
			{
				if (curColor != prevColor)
				{
					result = std::min(result, costs[lastHouse][curColor]);
				}
			}
			caches[lastHouse][prevColor] = result;
		}

		for (int house = lastHouse - 1; house >= 1; house--)
		{
			for (int prevColor = 0; prevColor < COLOR_COUNT; prevColor++)
			{
				int result = std::numeric_limits<int>::max();
				for (int curColor = 0; curColor < COLOR_COUNT; curColor++)
				{
					if (curColor != prevColor)
					{
						result = std::min(result, caches[house + 1][curColor] + costs[house][curColor]);
					}
				}
				caches[house][prevColor] = result;
			}
		}

		int minCost = std::min(
			{ costs[0][0] + caches[1][0],
			costs[0][1] + caches[1][1],
			costs[0][2] + caches[1][2] });

		std::cout << minCost << '\n';
	}


};

int main()
{
	Soluter soluter;

	soluter.Input();

	soluter.Solve();

	return 0;
}