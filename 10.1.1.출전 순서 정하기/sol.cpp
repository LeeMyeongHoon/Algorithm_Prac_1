#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

struct Soluter
{
	int playerCount;
	std::set<int> koreas;
	std::vector<int> russias;

	void Input()
	{
		std::cin >> playerCount;

		for (int i = 0; i < playerCount; i++)
		{
			int rating;
			std::cin >> rating;
			russias.push_back(rating);
		}
		for (int i = 0; i < playerCount; i++)
		{
			int rating;
			std::cin >> rating;
			koreas.insert(rating);
		}
	}

	void Solve()
	{
		int winCount = 0;
		auto koreaMax = *koreas.rbegin();
		for (auto& russia : russias)
		{
			if (russia > koreaMax)
			{
				auto koreaMin = koreas.cbegin();
				koreas.erase(koreaMin);
			}
			else
			{
				koreas.erase(koreas.lower_bound(russia));
				winCount++;
			}
		}

		std::cout << winCount << '\n';
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