// https://algospot.com/judge/problem/read/FENCE

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Soluter
{
	static const size_t MAX_WALL_COUNT = 20000;

	size_t wallCount;
	size_t heights[MAX_WALL_COUNT];
	size_t maxArea = std::numeric_limits<size_t>::min();

	void Input()
	{
		std::cin >> wallCount;
		for (size_t wall = 0; wall < wallCount; wall++)
		{
			std::cin >> heights[wall];
		}
	}

	void FindMinArea(size_t beginWall, size_t lastWall)
	{
		assert(beginWall <= lastWall);
		if (beginWall == lastWall)
		{
			maxArea = std::max(maxArea, heights[beginWall]);

			return;
		}

		size_t midWall = (beginWall + lastWall) / 2;
		FindMinArea(beginWall, midWall);
		FindMinArea(midWall + 1, lastWall);

		size_t minHeight = std::min(heights[midWall], heights[midWall + 1]);
		maxArea = std::max(maxArea, 2 * minHeight);


		size_t leftWall = midWall;
		size_t rightWall = midWall + 1;
		size_t newHeight = std::numeric_limits<size_t>::max();

		for (;;)
		{
			if (leftWall - 1 >= beginWall)
			{
				if (rightWall + 1 <= lastWall)
				{
					if (heights[leftWall - 1] > heights[rightWall + 1])
					{
						newHeight = heights[leftWall - 1];
						leftWall--;
					}
					else
					{
						newHeight = heights[rightWall + 1];
						rightWall++;
					}
				}
				else
				{
					newHeight = heights[leftWall - 1];
					leftWall--;
				}
			}
			else
			{
				if (rightWall + 1 <= lastWall)
				{
					newHeight = heights[rightWall + 1];
					rightWall++;
				}
				else // 좌우로 뻗어나가지 못하는 경우
				{
					return;
				}
			}

			if (newHeight < minHeight)
			{
				minHeight = newHeight;
			}
			maxArea = std::max(maxArea, minHeight * (rightWall - leftWall + 1));
		}
	}

	void Solve()
	{
		FindMinArea(0, wallCount - 1);
		std::cout << maxArea << '\n';
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