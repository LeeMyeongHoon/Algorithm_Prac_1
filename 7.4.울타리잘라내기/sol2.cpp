// https://algospot.com/judge/problem/read/FENCE

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Soluter
{
	static const int MAX_WALL_COUNT = 20000;

	int wallCount;
	int heights[MAX_WALL_COUNT];
	int maxArea = std::numeric_limits<int>::min();

	void Input()
	{
		std::cin >> wallCount;
		for (int wall = 0; wall < wallCount; wall++)
		{
			std::cin >> heights[wall];
		}
	}

	void FindMinArea(int beginWall, int lastWall)
	{
		assert(beginWall <= lastWall);
		if (beginWall == lastWall)
		{
			maxArea = std::max(maxArea, heights[beginWall]);

			return;
		}

		int midWall = (beginWall + lastWall) / 2;
		FindMinArea(beginWall, midWall);
		FindMinArea(midWall + 1, lastWall);

		int minHeight = std::min(heights[midWall], heights[midWall + 1]);
		maxArea = std::max(maxArea, 2 * minHeight);


		int leftWall = midWall;
		int rightWall = midWall + 1;
		int newHeight = std::numeric_limits<int>::max();

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