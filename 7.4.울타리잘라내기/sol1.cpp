#include <vector>
#include <algorithm>

#ifdef Sol
std::vector<int> h;

int solve(int left, int right)
{
	if (left == right)
		return h[left];
	int mid = (left + right) / 2;
	int ret = std::max(solve(left, mid), solve(mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	int height = std::min(h[lo], h[hi]);
	ret = std::max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (/*hi < right && */ lo == left || h[lo - 1] < h[hi + 1])
		{
			++hi;
			height = std::min(height, h[hi]);
		}
		else
		{
			--lo;
			height = std::min(height, h[lo]);
		}

		ret = std::max(ret, height * (hi - lo - 1));
	}
	return ret;
}
#endif // Sol
