// https://www.acmicpc.net/problem/1780
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int data[2187][2187];
struct Soluter
{
	int size;
	int minusCount = 0;
	int plusCount = 0;
	int zeroCount = 0;


	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> data[i][j];
			}
		}
	}

	void Solve()
	{
		SetAllPaperCount(size, 0, 0);
		std::cout << minusCount << '\n' << zeroCount << '\n' << plusCount << '\n';
	}

	void SetAllPaperCount(int size, int beginI, int beginJ)
	{
		if (size == 1)
		{
			SetPaperCount(data[beginI][beginJ]);
			return;
		}

		if (IsAllSame(size, beginI, beginJ))
		{
			SetPaperCount(data[beginI][beginJ]);
			return;
		}

		int newSize = size / 3;
		for (int newBeginI = beginI; newBeginI < beginI + size; newBeginI += newSize)
		{
			for (int newBeginJ = beginJ; newBeginJ < beginJ + size; newBeginJ += newSize)
			{
				SetAllPaperCount(newSize, newBeginI, newBeginJ);
			}
		}
	}

	void SetPaperCount(int num)
	{
		if (num == -1)
		{
			minusCount++;
		}
		else if (num == +1)
		{
			plusCount++;
		}
		else // if (num == 0)
		{
			zeroCount++;
		}
	}

	bool IsAllSame(int size, int beginI, int beginJ)
	{
		int keyNum = data[beginI][beginJ];
		for (int i = beginI; i < beginI + size; i++)
		{
			for (int j = beginJ; j < beginJ + size; j++)
			{
				if (data[i][j] != keyNum)
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}