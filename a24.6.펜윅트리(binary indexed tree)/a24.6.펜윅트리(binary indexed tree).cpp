#include <iostream>
#include <algorithm>
#include <vector>

struct FerwickTree
{
	std::vector<int> tree;
	FerwickTree(int n)
		:tree(n)
	{
	}

	int sum(int pos)
	{
		pos++;
		int sum = 0;
		while (pos > 0)
		{
			sum += tree[pos];
			pos &= (pos - 1);
		}
		return sum;
	}

	void add(int pos,int val)
	{

	}
};