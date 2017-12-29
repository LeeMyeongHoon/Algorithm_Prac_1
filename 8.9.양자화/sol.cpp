//	https://algospot.com/judge/problem/read/QUANTIZE

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include <cmath>


struct Soluter
{
	int numCount;
	int partCount;

	int history[100][11];

	std::vector<int> numbers;
	std::vector<int> sums;
	std::vector<int> squareSums;

	void Input()
	{
		std::cin >> numCount >> partCount;

		numbers.assign(numCount, 0);
		for (auto& number : numbers)
		{
			std::cin >> number;
		}
	}

	void Solve()
	{
		for (auto& history1 : history)
		{
			for (auto& history2 : history1)
			{
				history2 = -1;
			}
		}

		std::sort(std::begin(numbers), std::end(numbers));

		sums.assign(numCount, 0);
		sums[0] = numbers[0];

		squareSums.assign(numCount, 0);
		squareSums[0] = numbers[0] * numbers[0];

		for (int i = 1; i < numCount; i++)
		{
			sums[i] = sums[i - 1] + numbers[i];
			squareSums[i] = squareSums[i - 1] + (numbers[i] * numbers[i]);
		}

		std::cout << GetMin(0, partCount) << '\n';
	}

	int GetMin(int begin, int partCount)
	{
		if (begin == numCount)
		{
			return 0;
		}

		if (partCount == 0)
		{
			return (std::numeric_limits<int>::max() / 3);
		}

		auto& cache = history[begin][partCount];

		if (cache != -1)
		{
			return cache;
		}

		cache = std::numeric_limits<int>::max();

		for (int partSize = 1; begin + partSize <= numCount; partSize++)
		{
			cache = std::min(cache, GetMinErrorInPart(begin, begin + partSize - 1) + GetMin(begin + partSize, partCount - 1));
		}

		return cache;
	}


	// 수학풀이 필요
	int GetMinErrorInPart(int begin, int last)
	{
		int sum;
		if (begin == 0)
		{
			sum = sums[last];
		}
		else
		{
			sum = sums[last] - sums[begin - 1];
		}


		int squareSum;
		if (begin == 0)
		{
			squareSum = squareSums[last];
		}
		else
		{
			squareSum = squareSums[last] - squareSums[begin - 1];
		}


		int m0 = (double)sum / (last - begin + 1);
		int m1 = m0 + 1;


		return std::min(squareSum - 2 * m1 * sum + (last - begin + 1) * m1 * m1, squareSum - 2 * m0 * sum + (last - begin + 1) * m0 * m0);
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