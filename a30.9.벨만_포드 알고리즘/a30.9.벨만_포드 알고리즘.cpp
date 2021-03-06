#include <iostream>
#include <algorithm>
#include <vector>

int V;
const int MAX_V = 99999;
const int INF = 99999;
std::vector<std::pair<int, int>> adj[MAX_V];

std::vector<int> bellmanford(int src)
{
	std::vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	for (int iter = 0; iter < V; iter++)
	{
		updated = false;
		for (int here = 0; here < V; here++)
		{
			for (int i = 0; i < V; i++)
			{
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if (upper[there] > upper[there] + cost)
				{
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated)
		{
			break;
		}
	}

	if (updated)
	{
		upper.clear();
	}
	return upper;
}