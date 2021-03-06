// https://algospot.com/judge/problem/read/NERD2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstdio>

struct Point
{
	int x, y;
};

struct Soluter
{
	std::vector<Point> data;
	std::map<int, int> tree;
	int count;

	void Input()
	{
		std::cin >> count;
		data.assign(count, {});
		for (auto& point : data)
		{
			std::cin >> point.x >> point.y;
		}
	}

	void Solve()
	{
		int sum = 0;
		for (auto& point : data)
		{
			sum += Register(point.x, point.y);
		}

		std::cout << sum << '\n';
	}

	int Register(int x, int y)
	{
		if (IsDominated(x, y))
		{
			return tree.size();
		}

		removeDominated(x, y);
		tree[x] = y;

		return tree.size();
	}

	void removeDominated(int x, int y)
	{
		auto iter = tree.lower_bound(x);
		if (iter == std::begin(tree))
		{
			return;
		}
		--iter;
		for (;;)
		{
			if (iter->second > y)
			{
				break;
			}
			if (iter == std::begin(tree))
			{
				tree.erase(iter);
				break;
			}

			iter = tree.erase(iter);
			--iter;
		}
	}

	bool IsDominated(int x, int y)
	{
		auto moreRight = tree.lower_bound(x);
		if (moreRight == std::end(tree))
		{
			return false;
		}

		return y < moreRight->second;
	}
};

int main()
{
	int count;
	scanf("%d", &count);
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