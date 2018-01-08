// https://algospot.com/judge/problem/read/MORSE

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	int n;
	int m;
	int N_th;
	int validCount;
	int historyForBino[201][201];

	void Input()
	{
		std::cin >> n >> m >> N_th;
	}


	int GetBino(int n, int r)
	{
		if (n == r || r == 0)
		{
			return 1;
		}

		auto& cache = historyForBino[n][r];
		if (cache != -1)
		{
			return cache;
		}

		cache = GetBino(n - 1, r) + GetBino(n - 1, r - 1);
		if (cache > 1000000001)
		{
			cache = 1000000001;
		}

		return cache;
	}


	void Solve()
	{
		for (auto& historyForBino1 : historyForBino)
		{
			for (auto& historyForBino2 : historyForBino1)
			{
				historyForBino2 = -1;
			}
		}

		std::cout << Get_NthSignal(n, m, N_th) << '\n';
	}

	std::string Get_NthSignal(int n, int m, int Nth)
	{
		if (Nth == 1)
		{
			return std::string(n, '-') + std::string(m, 'o');
		}

		int skip = GetBino(n + m - 1, m);
		if (skip < Nth)
		{
			return "o" + Get_NthSignal(n, m - 1, Nth - skip);
		}

		else
		{
			return "-" + Get_NthSignal(n - 1, m, Nth);
		}
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