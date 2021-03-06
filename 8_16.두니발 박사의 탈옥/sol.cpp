// https://algospot.com/judge/problem/read/NUMB3RS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

double history[51][101][51];
struct Soluter
{
	bool linked[51][51];
	long long int linkedTownCount[51] = { 0 };

	long long int townCount;
	long long int passingDays;
	long long int prisonTown;

	long long int keyTownCount;
	long long int keyTowns[51];


	void Input()
	{
		std::cin >> townCount >> passingDays >> prisonTown;

		for (long long int town1 = 0; town1 < townCount; town1++)
		{
			for (long long int town2 = 0; town2 < townCount; town2++)
			{
				std::cin >> linked[town1][town2];
			}
		}

		std::cin >> keyTownCount;

		for (long long int i = 0; i < keyTownCount; i++)
		{
			std::cin >> keyTowns[i];
		}
	}

	void Solve()
	{
		for (long long int town1 = 0; town1 < townCount; town1++)
		{
			for (long long int town2 = 0; town2 < townCount; town2++)
			{
				if (linked[town1][town2])
				{
					++linkedTownCount[town1];
				}
			}
		}

		for (auto& history1 : history)
		{
			for (auto& history2 : history1)
			{
				for (auto& history3 : history2)
				{
					history3 = -1.0;
				}
			}
		}

		std::cout << std::fixed << std::setprecision(8);
		for (long long int i = 0; i < keyTownCount; i++)
		{
			std::cout << GetPercentage(prisonTown, passingDays, keyTowns[i]) << ' ';
		}
		std::cout << '\n';
	}


	double GetPercentage(long long int curTown, long long int days, long long int keyTown)
	{
		if (days == 0)
		{
			if (curTown == keyTown)
			{
				return 1.0;
			}
			else
			{
				return 0.0;
			}
		}

		auto& cache = history[curTown][days][keyTown];

		if (cache != -1.0)
		{
			return cache;
		}

		double percentage = 0.0;

		for (long long int nextTown = 0; nextTown < townCount; nextTown++)
		{
			if (linked[curTown][nextTown])
			{
				percentage += (GetPercentage(nextTown, days - 1, keyTown) * (1 / (double)linkedTownCount[curTown]));
			}
		}

		return cache = percentage;
	}
};

int main()
{
	long long int count;
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