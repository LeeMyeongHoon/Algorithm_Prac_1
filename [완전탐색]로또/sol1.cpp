// https://www.acmicpc.net/problem/6603
#include <algorithm>
#include <vector>
#include <iostream>

struct Soluter
{
	int allNumberCount;
	std::vector<int> allNumbers;
	std::vector<int> selectedNumbers;

	bool Input()
	{
		std::cin >> allNumberCount;
		if (allNumberCount == 0)
		{
			return false;
		}

		for (int i = 0; i < allNumberCount; i++)
		{
			int number;
			std::cin >> number;
			allNumbers.push_back(number);
		}
		return true;
	}

	void SetSelectedNumbers(int i)
	{
		if (selectedNumbers.size() == 6)
		{
			for (auto& selectedNumber : selectedNumbers)
			{
				std::cout << selectedNumber << ' ';
			}
			std::cout << '\n';
			return;
		}

		if (i >= allNumberCount)
		{
			return;
		}

		selectedNumbers.push_back(allNumbers[i]);
		SetSelectedNumbers(i + 1);
		selectedNumbers.pop_back();

		SetSelectedNumbers(i + 1);
	}

	void Solve()
	{
		if (allNumberCount != 0)
		{
			std::sort(std::begin(allNumbers), std::end(allNumbers));
			SetSelectedNumbers(0);
		}
	}
};

int main()
{
	std::vector<Soluter*> soluters;

	for (;;)
	{
		Soluter* soluter = new Soluter;
		if (soluter->Input())
		{
			soluters.push_back(soluter);	// move
			soluter = nullptr;
		}
		else
		{
			delete soluter;
			soluter = nullptr;
			break;
		}
	}

	for (auto& soluter : soluters)
	{
		soluter->Solve();
		std::cout << '\n';
		delete soluter;
	}

	return 0;
}