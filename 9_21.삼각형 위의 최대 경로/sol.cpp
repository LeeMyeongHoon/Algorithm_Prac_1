// https://algospot.com/judge/problem/read/TRIANGLEPATH
// 반복적 동적계획법 및 슬라이딩 윈도

#include <iostream>
#include <vector>
#include <algorithm>

int data[100][100];
struct Soluter
{
	int size;
	int data[100][100];
	int* topResult;
	int* bottomResult;

	void Input()
	{
		std::cin >> size;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < y + 1; x++)
			{
				std::cin >> data[x][y];
			}
		}
	}

	void Solve()
	{
		topResult = new int[size];
		bottomResult = new int[size];

		for (int x = 0; x < size; x++)
		{
			bottomResult[x] = data[x][size - 1];
		}

		for (int y = size - 2; y >= 0; y--)
		{
			for (int x = 0; x < y + 1; x++)
			{
				topResult[x] = data[x][y] + std::max(bottomResult[x], bottomResult[x + 1]);
			}
			std::swap(bottomResult, topResult);
		}
		std::cout << bottomResult[0] << std::endl;
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