// https://algospot.com/judge/problem/read/NUMB3RS

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int townCount;
	int passingDays;
	int prisonTown;
	bool linked[50][50];
	int keyTown;

	void Input()
	{
		std::cin >> townCount >> passingDays >> prisonTown;

		for (int town1 = 0; town1 < townCount; town1++)
		{
			for (int town2 = 0; town2 < townCount; town2++)
			{
				std::cin >> linked[town1][town2];
			}
		}

		std::cin >> keyTown;
	}

	void 
};