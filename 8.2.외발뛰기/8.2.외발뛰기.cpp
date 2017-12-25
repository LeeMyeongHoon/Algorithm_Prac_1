// https://algospot.com/judge/problem/read/JUMPGAME

#include <iostream>
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
			for (int j = 0; j < size; j++)
			{
				history[i][j] = -1;
				std::cin >> data[i][j];
			}
		}
	}

	bool Counting(int i, int j)
	{
		if (i >= size || j >= size)
		{
			return 0;
		}
		if (data[i][j] == 0)
		{
			return true;
		}
		if (history[i][j] != -1)
		{
			return history[i][j];
		}

		return history[i][j] = Counting(i + data[i][j], j) || Counting(i, j + data[i][j]);
	}

	void Solve()
	{
		if (Counting(0, 0) == true)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
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