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
	int totalCount = 0;
	int fanCount;
	int memberCount;

	void Input()
	{
		std::cin >> memberSexes >> fanSexes;
		fanCount = fanSexes.size();
		memberCount = memberSexes.size();
	}

	int Counting(int firstFan, int lastFan)
	{
		int subFanCount = lastFan - firstFan + 1;
		if (subFanCount < memberCount || firstFan < 0 || lastFan >= fanCount)
		{
			return 0;
		}

		// Find
		int firstMaleFan;
		int maleFanCount = 0;
		bool hasMaleFan = false;
		bool isFirstMaleFound = false;
		for (int fan = firstFan; fan <= lastFan; fan++)
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


		int totalCount = 0;

		// Left subset
		totalCount += Counting(firstFan, firstMaleFan - 1);

		// Right subset
		int lastMaleFan = firstMaleFan + maleFanCount - 1;
		totalCount += Counting(lastMaleFan + 1, lastFan);


		// Mid subset including maleFans.
		for (int headFan = firstMaleFan - memberCount + 1; headFan <= lastMaleFan; headFan++)
		{
			if (headFan < firstFan)
				continue;

			int tailFan = headFan + memberCount - 1;;
			if (tailFan > lastFan)
			{
				break;
			}

			bool canAllHandShake = true;

			int member = 0;
			for (int fan = headFan; fan <= tailFan; fan++, member++)
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

int main()
{
	int count;
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