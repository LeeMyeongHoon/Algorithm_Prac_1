#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int numCount;

	std::vector<int> allNumbers;

	void Input()
	{
		std::cin >> numCount;
		allNumbers.assign(numCount, 0);
		for (int i = 0; i < numCount; i++)
		{
			std::cin >> allNumbers[i];
		}
	}

	void Solve()
	{

	}

	int GetDifference(int left, int right)
	{

	}
};

#define SOL_EX
#ifdef SOL_EX

const int EMPTY = std::numeric_limits<int>::min();
int n, board[50];
int cache[50][50];
int play(int left, int right)
{
	if (left > right)
	{
		return 0;
	}
	int& ret = cache[left][right];
	if (ret != EMPTY)
	{
		return ret;
	}

	ret = std::max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	if (right - left + 1 >= 2)
	{
		ret = std::max(ret, -play(left + 2, right));
		ret = std::max(ret, -play(left, right - 2));
	}
	return ret;
}

#endif // SOL_EX
