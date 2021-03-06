#define 책내용
#ifdef 책내용
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct RMQ
{
	int n;
	std::vector<int> rangeMin;
	RMQ(const std::vector<int>& array)
	{
		n = array.size();
		rangeMin.assign(n * 4, {});
		init(array, 0, n - 1, 1);
	}

	int query(int keyLeft, int keyRight, int node, int rangeLeft, int rangeRight)
	{
		// 공집합인 경우, 최솟값 따윈 없으니
		if (keyRight < rangeLeft || rangeRight < keyLeft)
		{
			return INT_MAX;
		}

		// 
		if (keyLeft <= rangeLeft && rangeRight <= keyRight)
		{
			return rangeMin[node];
		}
		int rangeMid = (rangeLeft + rangeRight) / 2;

		return std::min(query(keyLeft, keyRight, node * 2, rangeLeft, rangeMid), query(keyLeft, keyRight, node * 2 + 1, rangeMid + 1, rangeRight));
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	int init(const std::vector<int>& array, int left, int right, int node)
	{
		if (left == right)
		{
			return rangeMin[node] = array[left];
		}
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);

		return rangeMin[node] = std::min(leftMin, rightMin);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index)
		{
			return rangeMin[node];
		}
		if (nodeLeft == nodeRight)
		{
			return rangeMin[node] = newValue;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = std::min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
};

#endif // 책 내용
