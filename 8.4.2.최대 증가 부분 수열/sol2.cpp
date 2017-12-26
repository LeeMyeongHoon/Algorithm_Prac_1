#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	int str[500];
	int history[500];

	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			std::cin >> str[i];
			history[i] = -1;
		}
	}


	int GetMaxLength(int start)
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

		int maxLength = 1;
		for (int next = start + 1; next < size; next++)
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
		int max = -1;
		for (int start = 0; start < size; start++)
		{
			int newMaxLength = GetMaxLength(start);
			if (max < newMaxLength)
			{
				max = newMaxLength;
			}
		}

		std::cout << max << '\n';
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