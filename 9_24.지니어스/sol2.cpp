// https://algospot.com/judge/problem/read/GENIUS
// 재귀적 동적계획법(크기 문제로 메모제이션불가능 -> 느림)

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Soluter
{
	int allSongCount;
	int totalTime;
	int favorSongCount;

	int songLength[51];
	double prob[51][51];

	int favorSongs[11];

	void Input()
	{
		std::cin >> allSongCount >> totalTime >> favorSongCount;


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


	void Solve()
	{
		double dp[6][51] = { 0.0 };

		dp[0][0] = 1.0;

		for (int time = songLength[0]; time <= totalTime; time++)
		{
			for (int nextSong = 0; nextSong < allSongCount; nextSong++)
			{
				dp[time % 5][nextSong] = 0.0;
				for (int prevSong = 0; prevSong < allSongCount; prevSong++)
				{
					int prevTime = time - songLength[prevSong];

					if (prevTime >= 0)
					{
						dp[time % 5][nextSong] += (dp[prevTime % 5][prevSong] * prob[prevSong][nextSong]);
					}
				}
			}
		}

		std::vector<double> retProb(favorSongCount, 0.0);
		for (int song = 0; song < allSongCount; song++)
		{
			for (int start = totalTime - songLength[song] + 1; start <= totalTime; start++)
			{
				retProb[song] += dp[start % 5][song];
			}
		}

		std::cout << std::fixed << std::setprecision(8);
		for (auto& prob1 : retProb)
		{
			std::cout << prob1 << ' ';
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