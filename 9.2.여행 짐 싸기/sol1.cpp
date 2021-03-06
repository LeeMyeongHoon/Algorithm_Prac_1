// https://algospot.com/judge/problem/read/PACKING

// 최대 절박도만 구하는 풀이

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

int history[1001][101];
struct Soluter
{
	int itemCount;
	int capacity;
	int maxTotalValue;

	std::vector<std::string> names;
	std::vector<int> volumes;
	std::vector<int> values;
	std::vector<int> selectedItems;


	void Input()
	{
		std::cin >> itemCount >> capacity;
		names.assign(itemCount, "");
		volumes.assign(itemCount, 0);
		values.assign(itemCount, 0);

		for (int i = 0; i < itemCount; i++)
		{
			std::cin >> names[i] >> volumes[i] >> values[i];
		}
	}

	int GetMaxTotalValue(int capacity, int curItem)
	{
		if (capacity < 0)
		{
			return std::numeric_limits<int>::min();
		}
		if (curItem == itemCount)
		{
			return 0;
		}

		auto& cache = history[capacity][curItem];
		if (cache != -1)
		{
			return cache;
		}

		return cache = std::max(values[curItem] + GetMaxTotalValue(capacity - volumes[curItem], curItem + 1), GetMaxTotalValue(capacity, curItem + 1));
	}

	void Solve()
	{
		for (auto& history1 : history)
		{
			for (auto& history2 : history1)
			{
				history2 = -1;
			}
		}
		maxTotalValue = GetMaxTotalValue(capacity, 0);
		MakeList(capacity, 0);

		std::cout << maxTotalValue << ' ' << selectedItems.size() << '\n';
		for (auto& item : selectedItems)
		{
			std::cout << names[item] << '\n';
		}
	}

	void MakeList(int capacity, int item)
	{
		if (item == itemCount)
		{
			return;
		}
		if (GetMaxTotalValue(capacity, item) == GetMaxTotalValue(capacity, item + 1))
		{
			MakeList(capacity, item + 1);
		}
		else
		{
			selectedItems.push_back(item);
			MakeList(capacity - volumes[item], item + 1);
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