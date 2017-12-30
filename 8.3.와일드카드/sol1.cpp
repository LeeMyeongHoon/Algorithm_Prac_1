// https://algospot.com/judge/problem/read/WILDCARD
// 1.완전탐색


#ifdef Sol
#include <string>

using std::string;

bool match(const string& w, const string& s)
{
	size_t pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || s[pos] == w[pos]))
	{
		pos++;
	}

	if (pos == w.size())
	{
		return pos == s.size();
	}

	if (w[pos] == '*')
	{
		for (size_t skip = 0; pos + skip < s.size(); skip++)
		{
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
			{
				return true;
			}
		}
	}

	return false;
}

// 2.동적
size_t cache[101][101];
string W, S;
bool matchMemoized(size_t w, size_t s)
{
	size_t& ret = cache[w][s];
	if (ret != -1)
	{
		return ret;
	}
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
	{
		++w;
		++s;
	}

	if (w == W.size())
	{
		return ret = (s == S.size());
	}

	if (W[w] == '*')
	{
		for (size_t skip = 0; skip + s < S.size(); skip++)
		{
			if (matchMemoized(w + 1, s + skip))
			{
				return ret = 1;
			}
		}
	}

	return ret = 0;
}

#endif // Sol
