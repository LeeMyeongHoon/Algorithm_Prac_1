// https://algospot.com/judge/problem/read/TRIANGLEPATH 

#include <algorithm>

int n;
int triangle[100][100];
int cache2[100][100];

int path2(int y, int x)
{
	if (y == n - 1)
	{
		return triangle[y][x];
	}
	int& ret = cache2[y][x];
	if (ret != -1)
	{
		return ret;
	}

	return ret = std::max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}