// https://algospot.com/judge/problem/read/FANMEETING
// 
#define Sol
#ifdef Sol

#include <iostream>
#include <string>
#include <vector>

struct Soluter
{
	std::string memberSexes;
	std::string fanSexes;
	long long int totalCount = 0;
	long long int fanCount;
	long long int memberCount;

	void Input()
	{
		std::cin >> memberSexes >> fanSexes;
		fanCount = fanSexes.size();
		memberCount = memberSexes.size();
	}

	long long int Counting(long long int firstFan, long long int lastFan)
	{
		long long int subFanCount = lastFan - firstFan + 1;
		if (subFanCount < memberCount || firstFan < 0 || lastFan >= fanCount)
		{
			return 0;
		}

		// Find
		long long int firstMaleFan;
		long long int maleFanCount = 0;
		bool hasMaleFan = false;
		bool isFirstMaleFound = false;
		for (long long int fan = firstFan; fan <= lastFan; fan++)
		{
			if (fanSexes[fan] == 'M')
			{
				maleFanCount++;
				if (!isFirstMaleFound)
				{
					firstMaleFan = fan;
					isFirstMaleFound = true;
				}
			}

			else
			{
				if (isFirstMaleFound)
				{
					break;
				}
			}
		}

		if (!isFirstMaleFound)
		{
			return subFanCount - memberCount + 1;
		}


		long long int totalCount = 0;

		// Left subset
		totalCount += Counting(firstFan, firstMaleFan - 1);

		// Right subset
		long long int lastMaleFan = firstMaleFan + maleFanCount - 1;
		totalCount += Counting(lastMaleFan + 1, lastFan);


		// Mid subset including maleFans.
		for (long long int headFan = firstMaleFan - memberCount + 1; headFan <= lastMaleFan; headFan++)
		{
			if (headFan < firstFan)
				continue;

			long long int tailFan = headFan + memberCount - 1;;
			if (tailFan > lastFan)
			{
				break;
			}

			bool canAllHandShake = true;

			long long int member = 0;
			for (long long int fan = headFan; fan <= tailFan; fan++, member++)
			{
				if (memberSexes[member] == 'M' && fanSexes[fan] == 'M')
				{
					canAllHandShake = false;
					break;
				}
			}

			if (canAllHandShake)
			{
				totalCount++;
			}
		}

		return totalCount;
	}

	void Solve()
	{
		std::cout << Counting(0, fanCount - 1) << '\n';
	}
};

long long int main()
{
	long long int count;
	std::cin >> count;
	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}
}

#endif 