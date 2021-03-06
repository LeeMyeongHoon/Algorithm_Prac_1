#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int totalMoney;
	int foodCount;
	std::vector<int> foodPrices;
	std::vector<int> foodValues;

	int* prevResult;
	int* curResult;

	void Input()
	{
		std::cin >> foodCount >> totalMoney;
		
		foodPrices.assign(foodCount, 0);
		foodValues.assign(foodCount, 0);
		for (int i = 0; i < foodCount; i++)
		{
			std::cin >> foodPrices[i] >> foodValues[i];
		}
	}

	void Solve()
	{
		totalMoney /= 100;
		for (auto& foodPrice : foodPrices)
		{
			foodPrice /= 100;
		}

	}
};

int main()
{

	return 0;
}