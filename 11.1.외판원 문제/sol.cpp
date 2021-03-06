#include <iostream>
#include <algorithm>
#include <vector>

// TSP를 해결하는 완전 타맥의 구현
const double INF = std::numeric_limits<double>::max();
const int MAX = 30;

int n;

double dist[MAX][MAX];

double best;
double minEdge[MAX];

double simpleHeuristic(std::vector<bool>& visited)
{
	double ret = minEdge[0];
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			ret += minEdge[i];
		}
	}
	return ret;
}

void search(std::vector<int>& path, std::vector<bool>& visited, double currentLength)
{
	int here = path.back();

	if (path.size() == n)
	{
		best = std::min(best, currentLength + dist[here][0]);
		return;
	}
	if (best <= currentLength)
	{
		return;
	}

	for (int next = 0; next < n; next++)
	{
		if (visited[next])
		{
			continue;
		}
		path.push_back(next);
		visited[next] = true;
		search(path, visited, currentLength + dist[here][next]);
		visited[next] = false;
		path.pop_back();
	}
}

double solve()
{
	best = std::numeric_limits<double>::max();

	std::vector<bool> visited(n, false);
	std::vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}