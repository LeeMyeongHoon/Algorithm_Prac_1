// https://algospot.com/judge/problem/read/TRIANGLEPATH 



#ifdef ¿Á±Õ»£√‚
#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int size;
	int data[100][100];
	int history[100][100];

	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				std::cin >> data[i][j];
				history[i][j] = -1;
			}
		}
	}

	int GetSum(int i, int j)
	{
		if (j == size - 1)
		{
			return data[i][j];
		}

		auto& cache = history[i][j];

		if (cache != -1)
		{
			return cache;
		}

		return cache = data[i][j] + std::max(GetSum(i + 1, j), GetSum(i + 1, j + 1));
	}

	void Solve()
	{
		std::cout << GetSum(0, 0) << '\n';
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
#endif // ¿Á±Õ»£√‚
