// https://algospot.com/judge/problem/read/PICNIC
//#define Sol3
#ifdef Sol3

size_t n;
bool areFriends[10][10];

size_t countPairings(bool taken[10])
{
	size_t firstFree = -1;
	for (size_t i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
	{
		return 1;
	}

	size_t ret = 0;

	for (size_t pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}


#endif // Sol1
