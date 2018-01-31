#include <iostream>
#include <vector>
#include <algorithm>

struct SegmentTree
{
	std::vector<int> data = { 1,2,3,4,5,6,7,8,9 };
	std::vector<int> tree;
	int n;

	SegmentTree()
	{
		n = data.size() - 1;
		tree.assign(4 * n, {});
		Init(1, 0, n - 1);
	}

	int Init(int node, int left, int right)
	{
		if (left == right)
		{
			return tree[node] = data[left];
		}
		int mid = (left + right) / 2;

		return tree[node] = Init(node * 2, left, mid) + Init(node * 2 + 1, mid + 1, right);
	}

	int sum(int node, int curLeft, int curRight, int keyLeft, int keyRight)
	{
		if (curRight < keyLeft || keyRight < curLeft)
		{
			return 0;
		}

		if (keyLeft <= curLeft && curRight <= keyRight)
		{
			return tree[node];
		}

		int curMid = (curRight + curLeft) / 2;

		return sum(node * 2, curLeft, curMid, keyLeft, keyRight) + sum(node * 2 + 1, curMid + 1, curRight, keyLeft, keyRight);
	}

	int sum(int keyLeft, int keyRight)
	{
		return sum(1, 0, n - 1, keyLeft, keyRight);
	}
};

int main()
{
	return 0;
}