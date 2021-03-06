// https://algospot.com/judge/problem/read/SNAIL
// 위에 문제에서 확률이 50%인 경우....

#ifdef 확률50%
#include <iostream>
#include <vector>
#include <cmath>

size_t	history[1000][2003];
struct Soluter
{
	size_t totalHeight;
	size_t totalDay;

	void Input()
	{
		std::cin >> totalHeight >> totalDay;

		for (auto& history0 : history)
		{
			for (auto& history1 : history0)
			{
				history1 = -1;
			}
		}
	}

	size_t GetClimbDay(size_t curDay, size_t curHeight)
	{
		if (curDay == totalDay)
		{
			if (curHeight >= totalHeight)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		auto& cache = history[curDay][curHeight];

		if (cache != -1)
		{
			return cache;
		}

		return cache = GetClimbDay(curDay + 1, curHeight + 1) + GetClimbDay(curDay + 1, curHeight + 2);
	}

	void Solve()
	{
		std::cout << GetClimbDay(0, 0) / pow(2.0l, totalDay) << '\n';
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
#endif // 확률50%
