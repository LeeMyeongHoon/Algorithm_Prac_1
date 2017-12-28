#include <iostream>
#include <vector>

struct Soluter
{
	int totalWidth;
	int history[101];
	enum { MOD = 1000000007u };

	void Input()
	{
		std::cin >> totalWidth;
	}

	void Solve()
	{
		for (auto& history0 : history)
		{
			history0 = -1;
		}
		std::cout << AsymmetricCounting(totalWidth) << '\n';
	}

	int AsymmetricCounting(int curWidth)
	{
		if (curWidth % 2 == 1)
		{
			return (AllCounting(curWidth) - AllCounting((curWidth) / 2) + MOD) % MOD;
		}
		else
		{
			int ret = AllCounting(curWidth);
			ret = (ret - AllCounting(curWidth / 2) + MOD) % MOD;
			ret = (ret - AllCounting(curWidth / 2 - 1) + MOD) % MOD;
			return ret;
		}
	}

	int AllCounting(int curWidth)
	{
		if (curWidth <= 1)
		{
			return 1;
		}

		auto& cache = history[curWidth];

		if (cache != -1)
		{
			return cache;
		}

		return cache = (AllCounting(curWidth - 1) + AllCounting(curWidth - 2)) % MOD;
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