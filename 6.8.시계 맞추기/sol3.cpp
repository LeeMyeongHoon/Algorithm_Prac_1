// https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct Soluter
{
	using Time = size_t;
	using Clock = size_t;
	using Switch = size_t;

	static const size_t CLOCK_COUNT = 16;
	static const size_t SWITCH_COUNT = 10;

	Time times[CLOCK_COUNT];
	size_t minTotalPushCount = std::numeric_limits<size_t>::max();

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
		for (auto& time : times)
		{
			std::cin >> time;
		}
	}

	void SetMinTotalPushCount(size_t switchPushCount, Switch swtch, size_t curTotalPushCount)
	{
		bool isAllSet = true;
		for (auto& time : times)
		{
			if (time != 12)
			{
				isAllSet = false;
				break;
			}
		}
		if (isAllSet)
		{
			minTotalPushCount = std::min(curTotalPushCount, minTotalPushCount);
			return;
		}

		if (switchPushCount == 4 || swtch >= SWITCH_COUNT || curTotalPushCount >= minTotalPushCount)
		{
			return;
		}


		SetMinTotalPushCount(0, swtch + 1, curTotalPushCount);

		// save
		for (auto& connectedClock : connectedClocks[swtch])
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

		SetMinTotalPushCount(switchPushCount + 1, swtch, curTotalPushCount + 1);

		// load
		for (auto& connectedClock : connectedClocks[swtch])
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
	}

	void Solve()
	{
		SetMinTotalPushCount(0, 0, 0);

		if (minTotalPushCount == std::numeric_limits<size_t>::max())
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << minTotalPushCount << '\n';
		}
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