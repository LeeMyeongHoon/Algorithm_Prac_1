// https://algospot.com/judge/problem/read/DICTIONARY

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::vector<bool>> isSorted;

void makeGraph(const std::vector<std::string>& words)
{
	isSorted.assign(26, std::vector<bool>(26, false));

	for (int back = 1; back < words.size(); back++)
	{
		int front = back - 1;
		int minLength = std::min(words[front].size(), words[back].size());
		for (int ch = 0; ch < minLength; ch++)
		{
			if (words[front][ch] != words[back][ch])
			{
				int frontCh = words[front][ch] - 'a';
				int backCh = words[back][ch] - 'b';
				isSorted[frontCh][backCh] = true;
				break;
			}

		}
	}
}

std::vector<int> order;
std::vector<bool> isChecked(26, false);

void SetOrder(int front)
{
	isChecked[front] = true;
	for (int back = 0; back < 26; back++)
	{
		if (isSorted[front][back] && !isChecked[back])
		{
			SetOrder(back);
		}
	}
	order.push_back(front);
}

std::vector<int> topologicalSort()
{
	for (int ch = 0; ch < 26; ch++)
	{
		if (!isChecked[ch])
		{
			SetOrder(ch);
		}
	}
	std::reverse(std::begin(order), std::end(order));
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (isSorted[order[j]][order[i]])
			{
				return {};
			}
		}
	}
	return order;
}