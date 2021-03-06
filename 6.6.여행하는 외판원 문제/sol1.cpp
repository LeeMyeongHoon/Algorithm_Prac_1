// https://www.acmicpc.net/problem/10971
#ifdef Sol
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>

size_t n;	// 도시의 수
double dist[1000][1000];

double shortestPath(std::vector<size_t>& path, std::deque<bool>& visited, double currentLength)
{
	if (path.size() == n)
	{
		return currentLength + dist[path[0]][path.back()];
	}

	double ret = std::numeric_limits<double>::max();

	for (size_t next = 0; next < n; next++)
	{
		if (visited[next])
		{
			continue;
		}
		size_t here = path.back();
		path.push_back(next);
		visited[next] = true;
		double candidate = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = std::min(ret, candidate);

		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

#endif // Sol
