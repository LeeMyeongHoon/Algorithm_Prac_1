// https://www.acmicpc.net/problem/1780
#define Sol
#ifdef Sol

#include <iostream>
#include <vector>

static int data[2187][2187];

struct Soluter
{

	int maxSize;
	int counts[3] = { 0 ,0,0 };

	void Input()
	{
		std::cin >> maxSize;
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				std::cin >> data[i][j];
			}
		}
	}

	void Counting(int color)
	{
		counts[color + 1]++;
	}

	void SetCount(int beginI, int beginJ, int size)
	{
		if (size == 1)
		{
			Counting(data[beginI][beginJ]);
			return;
		}

		bool isAllSame = true;
		int curColor = data[beginI][beginJ];

		for (int i = beginI; i < beginI + size; i++)
		{
			for (int j = beginJ; j < beginJ + size; j++)
			{
				if (data[i][j] != curColor)
				{
					isAllSame = false;
					break;
				}
			}
			if (isAllSame == false)
			{
				break;
			}
		}

		if (isAllSame)
		{
			Counting(curColor);
		}

		else
		{
			int newSize = size / 3;

			SetCount(beginI, beginJ, newSize);
			SetCount(beginI, beginJ + newSize, newSize);
			SetCount(beginI, beginJ + 2 * newSize, newSize);
			SetCount(beginI + newSize, beginJ, newSize);
			SetCount(beginI + newSize, beginJ + newSize, newSize);
			SetCount(beginI + newSize, beginJ + 2 * newSize, newSize);
			SetCount(beginI + 2 * newSize, beginJ, newSize);
			SetCount(beginI + 2 * newSize, beginJ + newSize, newSize);
			SetCount(beginI + 2 * newSize, beginJ + 2 * newSize, newSize);
		}
	}

	void Solve()
	{
		SetCount(0, 0, maxSize);

		for (int i = 0; i < 3; i++)
		{
			std::cout << counts[i] << '\n';
		}
	}
};


int main()
{

	Soluter soluter;

	soluter.Input();

	soluter.Solve();

	return 0;
}

#endif

