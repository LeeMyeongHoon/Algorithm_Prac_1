#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int memberCount;
	int pairCount;
	std::vector<int> fathers;
	std::vector<std::pair<int, int>> pairs;

	void Input()
	{
		std::cin >> memberCount >> pairCount;

		fathers.assign(memberCount, {});
		for (int i = 1; i < memberCount; i++)
		{
			std::cin >> fathers[i];
		}

		pairs.assign(pairCount, {});
		for (auto& pair : pairs)
		{
			std::cin >> pair.first >> pair.second;
		}
	}

	void Solve()
	{

	}
};

int main()
{

	return 0;
}
