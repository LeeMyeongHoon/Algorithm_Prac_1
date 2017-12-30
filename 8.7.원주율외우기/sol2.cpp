#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>




struct Soluter
{
	std::string str;
	std::vector<size_t> data;
	size_t history[10000];

	void Input()
	{
		std::cin >> str;
		for (size_t i = 0; i < str.size(); i++)
		{
			char temp[2] = { str[i],'\0' };
			data.push_back(atoi(temp));
		}

		for (size_t i = 0; i < str.size(); i++)
		{
			history[i] = -1;
		}
	}

	size_t GetMinDifficulty(size_t start)
	{
		if (start == data.size())
		{
			return 0;
		}

		auto& cache = history[start];
		if (cache != -1)
		{
			return cache;
		}

		size_t min = 35000;

		for (size_t newSize = 3; newSize <= 5; newSize++)
		{
			if (start + newSize <= data.size())
			{
				min = std::min(min, GetDifficulty(start, start + newSize) + GetMinDifficulty(start + newSize));
			}
		}

		return cache = min;
	}

	void Solve()
	{
		std::cout << GetMinDifficulty(0) << '\n';
	}

	bool IsAllSame(size_t begin, size_t end)
	{
		size_t num = data[begin];
		for (size_t i = begin + 1; i < end; i++)
		{
			if (num != data[i])
			{
				return false;
			}
		}
		return true;
	}

	bool IsSequence(size_t begin, size_t end, size_t offset)
	{
		for (size_t i = begin; i < end - 1; i++)
		{
			if (data[i + 1] != data[i] + offset)
			{
				return false;
			}
		}
		return true;
	}

	bool IsTwoNumber(size_t begin, size_t end)
	{
		size_t num0 = data[begin];
		size_t num1 = data[begin + 1];

		bool switch0 = true;
		for (size_t i = begin + 2; i < end; i++)
		{
			if (switch0)
			{
				if (data[i] != num0)
				{
					return false;
				}
			}
			else
			{
				if (data[i] != num1)
				{
					return false;
				}
			}
			switch0 = !switch0;
		}

		return true;
	}

	size_t GetDifficulty(size_t begin, size_t end)
	{
		size_t offset = data[begin + 1] - data[begin];

		bool isArithSequnce = false;

		if (IsSequence(begin, end, offset))
		{
			if (offset == 0)
			{
				return 1;
			}
			else if (offset == 1 || offset == -1)
			{
				return 2;
			}
			else
			{
				isArithSequnce = true;
			}
		}

		if (IsTwoNumber(begin, end))
		{
			return 4;
		}


		if (isArithSequnce)
		{
			return 5;
		}

		return 10;
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