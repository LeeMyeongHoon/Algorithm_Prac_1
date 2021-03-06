// https://algospot.com/judge/problem/read/STRJOIN

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

struct Soluter
{
	int count;
	std::vector<int> lengthes;

	void Input()
	{
		std::cin >> count;
		for (int i = 0; i < count; i++)
		{
			int length;
			std::cin >> length;
			lengthes.push_back(length);
		}
	}

	void Solve()
	{
		using Heap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
		Heap heap = { std::begin(lengthes), std::end(lengthes) };

		int sum = 0;
		while (heap.size() != 1)
		{
			auto min0 = heap.top();
			heap.pop();

			auto min1 = heap.top();
			heap.pop();

			int newLength = min0 + min1;
			heap.push(newLength);
			sum += newLength;
		}

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