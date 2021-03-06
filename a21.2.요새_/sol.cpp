// C++14에서는 컴파일러에 의존하여 std::make_unique의 구현여부가 결정되니 사용시 주의 

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
#include <functional>

template<typename T>
T Square(T x)
{
	return x * x;
}

struct Wall
{
	int x;
	int y;
	int r;
	int id;

	bool operator==(const Wall& other)
	{
		return this->id == other.id;
	}

	bool CanInclude(Wall& child)
	{
		return Square(child.x - this->x) + Square(child.y - this->y) < Square(r) && this->r > child.r;
	}
};

struct TreeNode
{
	TreeNode() = default;
	std::vector<std::unique_ptr<TreeNode>> children;
};

struct Soluter
{
	int count;
	std::vector<Wall> walls;
	std::unique_ptr<TreeNode> rootNode;
	bool IsVisited[100] = { false };
	int longestPath = 0;

	void Input()
	{
		std::cin >> count;
		walls.assign(count, {});
		int id = 0;
		for (auto& wall : walls)
		{
			std::cin >> wall.x >> wall.y >> wall.r;
			wall.id = id++;
		}
	}

	bool CanMakeEdge(Wall& parent, Wall& child)
	{
		if (!parent.CanInclude(child))
		{
			return false;
		}
		for (auto& mid : walls)
		{
			if (parent == mid || child == mid)
			{
				continue;
			}
			if (parent.CanInclude(mid) && mid.CanInclude(child))
			{
				return false;
			}
		}
		return true;
	}

	void Solve()
	{
		rootNode = MakeTree(0);
		int maxHeight = GetMaxHeight(rootNode.get());
		std::cout << (maxHeight > longestPath ? maxHeight : longestPath) << '\n';
	}

	int GetMaxHeight(TreeNode* parent)
	{
		if (parent->children.empty())
		{
			return 0;
		}

		std::vector<int> childHeights;
		for (auto& child : parent->children)
		{
			childHeights.push_back(GetMaxHeight(child.get()));
		}

		if (childHeights.size() >= 2)
		{
			std::sort(std::begin(childHeights), std::end(childHeights), std::greater<int>{});
			longestPath = std::max(longestPath, 2 + childHeights[0] + childHeights[1]);
		}

		return childHeights.front() + 1;
	}


	std::unique_ptr<TreeNode> MakeTree(int root)
	{
		auto tree = std::make_unique<TreeNode>();

		for (int child = 1; child < walls.size(); child++)
		{
			if (CanMakeEdge(walls[root], walls[child]))
			{
				tree->children.push_back(MakeTree(child));
			}
		}
		return tree;
	}
};

int main()
{
	int count;
	std::cin >> count;

	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}
	return 0;
}