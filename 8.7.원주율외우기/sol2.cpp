#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>




struct Soluter
{
	std::string str;
	std::vector<int> data;
	int history[10000];

	void Input()
	{
		std::cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			char temp[2] = { str[i],'\0' };
			data.push_back(atoi(temp));
		}

		for (int i = 0; i < str.size(); i++)
		{
			history[i] = -1;
		}
	}

	int GetMinDifficulty(int start)
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

		int min = 35000;

		for (int newSize = 3; newSize <= 5; newSize++)
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

	bool IsAllSame(int begin, int end)
	{
		int num = data[begin];
		for (int i = begin + 1; i < end; i++)
		{
			if (num != data[i])
			{
				return false;
			}
		}
		return true;
	}

	bool IsSequence(int begin, int end, int offset)
	{
		for (int i = begin; i < end - 1; i++)
		{
			if (data[i + 1] != data[i] + offset)
			{
				return false;
			}
		}
		return true;
	}

	bool IsTwoNumber(int begin, int end)
	{
		int num0 = data[begin];
		int num1 = data[begin + 1];

		bool switch0 = true;
		for (int i = begin + 2; i < end; i++)
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

	int GetDifficulty(int begin, int end)
	{
		int offset = data[begin + 1] - data[begin];

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