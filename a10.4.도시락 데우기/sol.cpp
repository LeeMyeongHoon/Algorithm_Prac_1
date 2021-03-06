// https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Soluter
{
	int count;
	std::vector<int> heating;
	std::vector<int> eating;
	std::vector<std::pair<int, int>> times;

	void Input()
	{
		std::cin >> count;
		times.assign(count, {});

		for (int i = 0; i < count; i++)
		{
			int time;
			std::cin >> time;
			times[i].second = time;
		}

		for (int i = 0; i < count; i++)
		{
			int time;
			std::cin >> time;
			times[i].first = time;
		}
	}

	void Solve()
	{
		std::sort(std::begin(times), std::end(times), [](decltype(times)::value_type left, decltype(times)::value_type right) { return  left > right; });

		std::vector<int> eatingRemains;

		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += times[i].second;
			for (auto& eatingRemain : eatingRemains)
			{	
				eatingRemain -= times[i].second;
			}
			eatingRemains.push_back(times[i].first);
		}

		auto maxRemain = *std::max_element(std::begin(eatingRemains), std::end(eatingRemains));

		sum += maxRemain;

		std::cout << sum << '\n';
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