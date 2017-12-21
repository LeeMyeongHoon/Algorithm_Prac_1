// https://algospot.com/judge/problem/read/CLOCKSYNC
#ifdef Sol
#define Sol

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct Soluter
{
	using Time = int;
	using Switch = int;
	using Clock = int;

	static const int CLOCK_COUNT = 16;
	static const int SWITCH_COUNT = 10;

	Time times[CLOCK_COUNT];
	int minPushCount = std::numeric_limits<int>::max();

	std::vector<Clock> connectedClocks[SWITCH_COUNT] =
	{
		{0,1,2},
		{3,7,9,11},
		{4,10,14,15},
		{0,4,5,6,7},
		{6,7,8,10,12},
		{0,2,14,15},
		{3,14,15},
		{4,5,7,14,15},
		{1,2,3,4,5},
		{3,4,5,9,13}
	};

	void Input()
	{
		for (int i = 0; i < CLOCK_COUNT; i++)
		{
			std::cin >> times[i];
		}
	}

	void SetMinPushCount(int totalPushCount, Switch swich, int switchPushCount)
	{
		if (totalPushCount >= minPushCount || swich >= SWITCH_COUNT || switchPushCount >= 4)
		{
			return;
		}

		bool isAllSet = true;
		for (Clock clock = 0; clock < CLOCK_COUNT; clock++)
		{
			if (times[clock] != 12)
			{
				isAllSet = false;
				break;
			}
		}
		if (isAllSet)
		{
			minPushCount = std::min(minPushCount, totalPushCount);
			return;
		}

		for (auto& connectedClock : connectedClocks[swich])
		{
			if (times[connectedClock] == 12)
			{
				times[connectedClock] = 3;
			}
			else
			{
				times[connectedClock] += 3;
			}
		}
		SetMinPushCount(totalPushCount + 1, swich, switchPushCount + 1);
		for (auto& connectedClock : connectedClocks[swich])
		{
			if (times[connectedClock] == 3)
			{
				times[connectedClock] = 12;
			}
			else
			{
				times[connectedClock] -= 3;
			}
		}

		SetMinPushCount(totalPushCount, swich + 1, 0);
	}

	void Solve()
	{
		SetMinPushCount(0, 0, 0);
		if (minPushCount == std::numeric_limits<int>::max())
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << minPushCount << '\n';
		}
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
#endif // Sol
