#include <iostream>
#include <vector>

struct DisjoinSet
{
	std::vector<int> parents;
	std::vector<int> rank;

	DisjoinSet(int n)
		: parents(n), rank(n)
	{
	}

	int find(int u)
	{
		if (parents[u] == u)
		{
			return u;
		}

		return u = find(parents[u]);
	}

	void Merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if (u == v)
		{
			return;
		}

		if (rank[u] < rank[v])
		{
			auto temp = u;
			u = v;
			v = temp;
		}

		parents[v] = u;

		if (rank[u] == rank[v])
		{
			++rank[u];
		}
	}
};