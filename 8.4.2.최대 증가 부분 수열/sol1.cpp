#include <iostream>
#include <vector>
#include <algorithm>

int n;
int cache[100];
int S[100];

int lis2(int start)
{
	int& ret = cache[start];
	if (ret != -1)
	{
		return ret;
	}

	ret = 1;
	for (int next = start; next < n; next++)
	{
		if (S[start] < S[next])
		{
			ret = std::max(ret, lis2(next) + 1);
		}
	}
	return ret;
}

