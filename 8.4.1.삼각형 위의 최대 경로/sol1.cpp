// https://algospot.com/judge/problem/read/TRIANGLEPATH 

#include <algorithm>

size_t n;
size_t triangle[100][100];
size_t cache2[100][100];

size_t path2(size_t y, size_t x)
{
	if (y == n - 1)
	{
		return triangle[y][x];
	}
	size_t& ret = cache2[y][x];
	if (ret != -1)
	{
		return ret;
	}

	return ret = std::max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}