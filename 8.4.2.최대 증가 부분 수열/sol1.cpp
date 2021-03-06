#include <iostream>
#include <vector>
#include <algorithm>

size_t n;
size_t cache[100];
size_t S[100];

size_t lis2(size_t start)
{
	size_t& ret = cache[start];
	if (ret != -1)
	{
		return ret;
	}

	ret = 1;
	for (size_t next = start; next < n; next++)
	{
		if (S[start] < S[next])
		{
			ret = std::max(ret, lis2(next) + 1);
		}
	}
	return ret;
}

