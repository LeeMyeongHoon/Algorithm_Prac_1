#include <iostream>
#include <algorithm>
#include <vector>

struct Soluters
{
	int numCount;
	int quanCount;
	std::vector<int> numbers;

	void Input()
	{
		std::cin >> numCount >> quanCount;
		for (int i = 0; i < numCount; i++)
		{
			int num;
			std::cin >> num;
			numbers.push_back(num);
		}
	}

	void Solve()
	{
		

	}
};