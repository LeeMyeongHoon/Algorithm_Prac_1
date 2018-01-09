#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int foodCount;
	int totalBudget;
	int dp[1000];

	std::vector<int> prices;
	std::vector<int> values;

	void Input()
	{
		std::cin >> foodCount >> totalBudget;

		prices.assign(foodCount, 0);
		values.assign(foodCount, 0);

		for (int i = 0; i < foodCount; i++)
		{
			std::cin >> prices[i] >> values[i];
		}
	}

	void Solve()
	{
		totalBudget /= 100;
		for (auto& foodPrice : prices)
		{
			foodPrice /= 100;
		}

		dp[0] = 0;
		for (int budget = 1; budget <= totalBudget; budget++)
		{
			dp[budget] = 0;
			for (int food = 0; food < foodCount; food++)
			{
				if (budget >= prices[food])
				{

				}
			}
		}
	}
};