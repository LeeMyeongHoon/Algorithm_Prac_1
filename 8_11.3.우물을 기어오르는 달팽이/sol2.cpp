// https://algospot.com/judge/problem/read/SNAIL
// 위에 문제에서 확률이 50%인 경우....

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double	history[1000][2003];
struct Soluter
{
	int totalHeight;
	int totalDay;

	void Input()
	{
		std::cin >> totalHeight >> totalDay;
	}

	double GetClimbDay(int curDay, int curHeight)
	{

		if (curDay == totalDay)
		{
			if (curHeight >= totalHeight)
			{
				return 1.0l;
			}
			else
			{
				return 0.0l;
			}
		}

		auto& cache = history[curDay][curHeight];

		if (cache != -1.0l)
		{
			return cache;
		}

		return cache = 0.25l * GetClimbDay(curDay + 1, curHeight + 1) + 0.75l * GetClimbDay(curDay + 1, curHeight + 2);
	}

	void Solve()
	{
		for (auto& history0 : history)
		{
			for (auto& history1 : history0)
			{
				history1 = -1.0l;
			}
		}
		std::cout << std::fixed << std::setprecision(10) << GetClimbDay(0, 0) << '\n';
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