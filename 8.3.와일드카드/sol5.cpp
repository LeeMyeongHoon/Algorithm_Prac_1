// https://algospot.com/judge/problem/read/WILDCARD
// 완전탐색

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


struct Soluter
{
	int wordCount;
	std::string words[50];
	std::string keyWord;

	int history[50][100][100];

	void Input()
	{
		std::cin >> keyWord >> wordCount;
		for (int i = 0; i < wordCount; i++)
		{
			std::cin >> words[i];
		}

	}

	bool IsMatched(int keyPos, int wordPos, int wordNum)
	{
		auto& cachce = history[wordNum][keyPos][wordPos];
		auto& word = words[wordNum];

		if (keyPos >= keyWord.size() || wordPos >= word.size())
		{
			return false;
		}

		if (cachce != -1)
		{
			return false;
		}

		for (;;)
		{
			if (keyPos == keyWord.size())
			{
				if (wordPos == word.size())
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			if (keyWord[keyPos] == '*')
			{
				if (keyPos == keyWord.size() - 1)
				{
					return cachce = true;
				}
				for (int skip = 0; wordPos + skip < word.size(); skip++)
				{
					if (IsMatched(keyPos + 1, wordPos + skip, wordNum))
					{
						return cachce = true;
					}
				}
			}

			if (keyWord[keyPos] == word[wordPos] || keyWord[keyPos] == '?')
			{
				keyPos++;
				wordPos++;
			}
			else
			{
				return cachce = false;
			}

		}
	}

	void Solve()
	{
		std::sort(std::begin(words), std::begin(words) + wordCount);

		for (auto& history0 : history)
		{
			for (auto& history1 : history0)
			{
				for (auto& history2 : history1)
				{
					history2 = -1;
				}
			}
		}

		for (int i = 0; i < wordCount; i++)
		{
			if (IsMatched(0, 0, i))
			{
				std::cout << words[i] << '\n';
			}
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