// https://algospot.com/judge/problem/read/PICNIC
#define Sol
#ifdef Sol

#include <iostream>
#include <vector>

struct Soluter
{
	size_t studentCount = 0;
	size_t friendPairCount = 0;
	bool areFriends[10][10] = { {false} };

	bool isPaired[10] = { false };

	void Input()
	{
		std::cin >> studentCount >> friendPairCount;
		for (size_t i = 0; i < friendPairCount; i++)
		{
			size_t stu1, stu2;
			std::cin >> stu1 >> stu2;
			areFriends[stu1][stu2] = true;
			areFriends[stu2][stu1] = true;

		}
	}

	size_t GetPicnicPairingCount()
	{
		size_t freeStudent = -1;
		for (size_t stu = 0; stu < studentCount; stu++)
		{
			if (!isPaired[stu])
			{
				freeStudent = stu;
				break;
			}
		}

		if (freeStudent == -1)
		{
			return 1;
		}

		size_t picnicPairingCount = 0;
		for (size_t partner = freeStudent + 1; partner < studentCount; partner++)
		{
			if (!isPaired[partner] && areFriends[freeStudent][partner])
			{
				isPaired[partner] = true;
				isPaired[freeStudent] = true;
				picnicPairingCount += GetPicnicPairingCount();
				isPaired[partner] = false;
				isPaired[freeStudent] = false;
			}
		}

		return picnicPairingCount;
	}

	void Solve()
	{
		std::cout << GetPicnicPairingCount() << '\n';
	}
};

size_t main()
{
	size_t count;
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

	return 0;
}

#endif // Sol