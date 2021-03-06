#include <vector>
#include <algorithm>

#ifdef Sol
std::vector<size_t> h;

size_t solve(size_t left, size_t right)
{
	if (left == right)
		return h[left];
	size_t mid = (left + right) / 2;
	size_t ret = std::max(solve(left, mid), solve(mid + 1, right));
	size_t lo = mid;
	size_t hi = mid + 1;
	size_t height = std::min(h[lo], h[hi]);
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
