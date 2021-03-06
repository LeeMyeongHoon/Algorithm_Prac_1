// 오버플로 무시;;;

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int numCount;
	int Nth;
	int numbers[500];
	int lisLengthes[500];
	int lisCounts[500];

	void Input()
	{
		std::cin >> numCount/* >> Nth*/;
		for (int i = 0; i < numCount; i++)
		{
			std::cin >> numbers[i];
		}
	}

	int& GetLisCountCache(int start) { return lisCounts[start + 1]; }
	int& GetLisLengthCache(int start) { return lisLengthes[start + 1]; }

	int GetLisLengh(int start)
	{
		if (start == numCount - 1)
		{
			return 1;
		}

		auto& cache = GetLisLengthCache(start);

		if (cache != -1)
		{
			return cache;
		}

		int length = -1;
		if (start != -1)
		{
			for (int next = start + 1; next < numCount; next++)
			{
				if (numbers[start] < numbers[next])
				{
					length = std::max(length, 1 + GetLisLengh(next));
				}
			}
		}

		else
		{
			for (int next = start + 1; next < numCount; next++)
			{
				length = std::max(length, 1 + GetLisLengh(next));
			}
		}

		return cache = length;
	}

	int GetLisCount(int cur)
	{
		if (GetLisLengh(cur) == 1)
		{
			return 1;
		}

		auto& cache = lisCounts[cur];

		if (cache != -1)
		{
			return cache;
		}

		int count = 0;
		for (int next = cur + 1; next < numCount; next++)
		{
			if (numbers[cur] < numbers[next] && GetLisLengh(cur) == GetLisLengh(next) + 1)
			{
				count += GetLisCount(next);
			}
		}

		count = std::max(count, GetLisCount(cur + 1));

		return cache = count;
	}

	void Solve()
	{
		for (auto& lisLength : lisLengthes)
		{
			lisLength = -1;
		}
		for (auto& lisCount : lisCounts)
		{
			lisCount = -1;
		}
	}
};

int main()
{
	Soluter sol;
	sol.Input();
	sol.Solve();

	std::cout << sol.GetLisCount(-1) << '\n';

	return 0;
}