#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	size_t size;
	size_t str[500];
	size_t history[500];

	void Input()
	{
		std::cin >> size;
		for (size_t i = 0; i < size; i++)
		{
			std::cin >> str[i];
			history[i] = -1;
		}
	}


	size_t GetMaxLength(size_t start)
	{
		if (start == size - 1)
		{
			return 1;
		}

		auto& cache = history[start];

		if (cache != -1)
		{
			return cache;
		}

		size_t maxLength = 1;
		for (size_t next = start + 1; next < size; next++)
		{
			if (str[start] < str[next])
			{
				auto nextMaxLength = GetMaxLength(next) + 1;
				if (maxLength < nextMaxLength)
				{
					maxLength = nextMaxLength;
				}
			}
		}

		return cache = maxLength;
	}

	void Solve()
	{
		size_t max = -1;
		for (size_t start = 0; start < size; start++)
		{
			size_t newMaxLength = GetMaxLength(start);
			if (max < newMaxLength)
			{
				max = newMaxLength;
			}
		}

		std::cout << max << '\n';
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