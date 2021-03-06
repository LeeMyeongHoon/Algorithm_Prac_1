#include <vector>
#include <queue>
#include <functional>

const int MAX_VERTEX_COUNT = 1000;
const int INF = 999999999;

int vertexCount = 100;

using Data = std::pair<int, int>;
#define _dist first
#define _vertex second

std::vector<std::pair<int, int>> adj[MAX_VERTEX_COUNT];
std::vector<int> dijkstra(int src)
{
	std::vector<int> dist(vertexCount, INF);
	dist[src] = 0;
	std::priority_queue<Data, std::greater<>> pq;
	pq.push(std::make_pair(0, src));
	while (!pq.empty())
	{
		int cost = pq.top()._dist;
		int here = pq.top()._vertex;
		pq.pop();

		if (dist[here] < cost)
		{
			continue;
		}

		for (int nextI = 0; nextI < adj[here].size(); nextI++)
		{
			int nextV = adj[here][nextI]._vertex;
			int newDist = cost + adj[here][nextI]._dist;
			if (dist[nextV] < newDist)
			{
				dist[nextV] = newDist;
				pq.push(std::make_pair(newDist, nextV));
			}
		}
	}

	return dist;
}