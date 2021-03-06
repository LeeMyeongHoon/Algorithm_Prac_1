// https://algospot.com/judge/problem/read/QUADTREE
#include <iostream>
#include <vector>
#include <string>
#include <cstring>


struct Soluter
{
	std::string data;

	size_t cur;

	void Input()
	{
		std::cin >> data;
	}

	inline std::string GetReverseData()
	{
		if (data[cur] == 'x')
		{
			cur++;
			std::string upLeft = GetReverseData();
			std::string upRight = GetReverseData();
			std::string downLeft = GetReverseData();
			std::string downRight = GetReverseData();
			return 'x' + downLeft + downRight + upLeft + upRight;
		}
		else
		{
			return { data[cur++] };
		}
	}

	void Solve()
	{
		cur = 0;
		std::cout << GetReverseData() << '\n';
	}
};

size_t main()
{
	size_t count;
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