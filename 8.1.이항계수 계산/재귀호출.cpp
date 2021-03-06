size_t bino(size_t n, size_t r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}
	else
	{
		return bino(n - 1, r - 1) + bino(n - 1, r);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////

size_t cache[30][30];		// 전부 -1로 초기화해야됨
size_t bino2(size_t n, size_t r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}
	if (cache[n][r] != -1)
	{
		return cache[n][r];
	}

	return cache[n][r] = bino2(n, r - 1) + bino2(n - 1, r - 1);
}