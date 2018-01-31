#ifdef 구간트리 연습 1
// http://isukorea.com/blog/home/waylight3/216

#include <iostream>
#include <vector>
#include <algorithm>

struct SegmentTree
{
	std::vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> tree;
	SegmentTree()
	{
		tree.assign(data.size() * 4, {});
	}

	int init(int node, int begin, int last)
	{
		if (begin == last)
		{
			return tree[node] = data[begin];
		}
		int mid = (begin + last) / 2;
		return tree[node] = init(node * 2, begin, mid) + init(node * 2 + 1, mid + 1, last);
	}

	int sum(int node, int curLeft, int curRight, const int keyLeft, const int keyRight)
	{
		// 교집합이 없는 경우(공집합)
		if (curRight < keyLeft || keyRight < curLeft)
		{
			return 0;
		}

		if (keyLeft <= curLeft && curRight <= keyRight)
		{
			return tree[node];
		}

		int curMid = (curLeft + curRight) / 2;
		return sum(node * 2, curLeft, curMid, keyLeft, keyRight) + sum(node * 2 + 1, curMid + 1, curRight, keyLeft, keyRight);
	}

	int sum(int keyLeft, int keyRight)
	{
		return sum(1, 0, data.size() - 1, keyLeft, keyRight);
	}

	void init()
	{
		init(1, 0, data.size() - 1);
	}
};

int main()
{
	SegmentTree segTree;

	segTree.init();

	std::cout << segTree.sum(1, 2) << '\n';

	return 0;
}
#endif // 구간트리 연습 1
