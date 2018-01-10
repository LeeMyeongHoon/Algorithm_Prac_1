// https://algospot.com/judge/problem/read/GENIUS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Soluter
{
	int allSongCount;
	double totalLength;
	int favorSongCount;

	int songLength[50];
	double prob[50][50];

	int favorSongs[10];

	void Input()
	{
		std::cin >> allSongCount >> totalLength >> favorSongCount;


		for (int i = 0; i < allSongCount; i++)
		{
			std::cin >> songLength[i];
		}

		for (int i = 0; i < allSongCount; i++)
		{
			for (int j = 0; j < allSongCount; j++)
			{
				std::cin >> prob[i][j];
			}
		}
		for (int i = 0; i < favorSongCount; i++)
		{
			std::cin >> favorSongs[i];
		}
	}

	// totalLength가 남았고, curSong을 재생할 것이다.
	std::vector<double> GetProb(int curLength, int curSong)
	{
		std::vector<double> retProb(favorSongCount, 0.0);

		int newLength = curLength + songLength[curSong];
		if (totalLength < (double)newLength)
		{
			for (int i = 0; i < favorSongCount; i++)
			{
				if (favorSongs[i] == curSong)
				{
					retProb[i] = 1.0;
					break;
				}
			}
			return retProb;
		}

		for (int nextSong = 0; nextSong < allSongCount; nextSong++)
		{
			auto temp = GetProb(newLength, nextSong);

			for (int i = 0; i < favorSongCount; i++)
			{
				retProb[i] += (temp[i] * prob[curSong][nextSong]);
			}
		}

		return retProb;
	}

	void Solve()
	{
		totalLength += 0.5;
		auto resultProbs = GetProb(totalLength, 0);

		std::cout << std::fixed << std::setprecision(8);
		for (auto& p : resultProbs)
		{
			std::cout << p << ' ';
		}
		std::cout << '\n';
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

	return 0;
}