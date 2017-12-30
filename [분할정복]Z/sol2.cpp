// https://www.acmicpc.net/problem/1074
// 빠른 4분할 search

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Soluter
{
	int size;

	int keyI;
	int keyJ;

	void Input()
	{
		std::cin >> size >> keyI >> keyJ;
	}

	int FindVisitCount(int size, int beginI, int beginJ)
	{
		if (size == 1)
		{
			if (beginI == keyI)
			{
				if (beginJ == keyJ)
				{
					return 1;
				}
				else
				{
					return 2;
				}
			}
			else
			{
				if (beginJ == keyJ)
				{
					return 3;
				}
				else
				{
					return 4;
				}
			}
		}

		else // if (size > 1)
		{
			int offset = pow(2, size - 1);

			if (keyI < beginI + offset) // 윗부분
			{
				if (keyJ < beginJ + offset) // 왼쪽부분
				{
					return FindVisitCount(size - 1, beginI, beginJ);
				}

				else // 오른쪽부분
				{
					return (offset * offset) + FindVisitCount(size - 1, beginI, beginJ + offset);
				}
			}

			else // 아랫 부분
			{
				if (keyJ < beginJ + offset) // 왼쪽 부분
				{
					return 2 * (offset * offset) + FindVisitCount(size - 1, beginI + offset, beginJ);
				}

				else // 오른쪽부분
				{
					return 3 * (offset * offset) + FindVisitCount(size - 1, beginI + offset, beginJ + offset);
				}
			}
		}
	}

	void Solve()
	{
		// 0,0 은 방문한것이 아니다. 따라서 반환값에서 -1 출력
		std::cout << FindVisitCount(size, 0, 0) - 1 << '\n';
	}
};

int main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}