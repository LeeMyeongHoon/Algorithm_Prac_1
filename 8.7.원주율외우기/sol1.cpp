#ifdef Sol1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>



bool IsAllSame(std::string& subData)
{
	int num = subData[0];
	for (int i = 1; i < subData.size(); i++)
	{
		if (num != subData[i])
		{
			return false;
		}
	}
	return true;
}

bool IsSequence(std::string& subData, int offset)
{
	for (int i = 0; i < subData.size() - 1; i++)
	{
		if (subData[i + 1] != subData[i] + offset)
		{
			return false;
		}
	}
	return true;
}

bool IsTwoNumber(std::string& subData)
{
	int num0 = subData[0];
	int num1 = subData[1];

	for (int i = 2; i < subData.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (subData[i] != num0)
			{
				return false;
			}
		}
		else
		{
			if (subData[i] != num1)
			{
				return false;
			}
		}
	}

	return true;
}

int GetDifficulty(std::string& subData)
{
	int offset = subData[1] - subData[0];

	bool isArithSequnce = false;

	if (IsSequence(subData, offset))
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

	if (IsTwoNumber(subData))
	{
		return 4;
	}


	if (isArithSequnce)
	{
		return 5;
	}

	return 10;
}

struct Soluter
{
	std::string data;
	int history[10000];

	void Input()
	{
		std::cin >> data;;

		for (int i = 0; i < data.size(); i++)
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
				std::string subData(std::begin(data) + start, std::begin(data) + start + newSize);
				min = std::min(min, GetDifficulty(subData) + GetMinDifficulty(start + newSize));
			}
		}

		return cache = min;
	}

	void Solve()
	{
		std::cout << GetMinDifficulty(0) << '\n';
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
#endif // Sol1
