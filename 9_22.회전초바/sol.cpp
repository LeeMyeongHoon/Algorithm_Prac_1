// https://algospot.com/judge/problem/read/SUSHI

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int foodCount;
	int totalBudget;
	int dp[201];

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
			int result = 0;
			for (int food = 0; food < foodCount; food++)
			{
				if (budget >= prices[food])
				{
					result = std::max(result, dp[(budget - prices[food]) % 201] + values[food]);
				}
			}
			dp[budget % 201] = result;
		}

		std::cout << dp[totalBudget % 201] << '\n';
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