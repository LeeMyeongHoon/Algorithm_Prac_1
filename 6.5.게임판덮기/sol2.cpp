// https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <vector>

enum class Blank
{
	BLOCK, EMPTY
};

struct Pos2D
{
	size_t x, y;
};

struct Soluter
{
	const Pos2D offset[4][3] =
	{
		{{0,0},{1,0},{1,+1}},	// ¤¡
		{{0,0},{0,+1},{1,+1}},	// ¤¤
		{{0,0},{1,0},{0,+1}},	// ¤¡ yÃà ´ëÄª
		{{0,0},{0,+1},{-1,+1}}	// ¤¤ yÃà ´ëÄª

	};

	size_t height;
	size_t totalWidth;
	size_t emptyCount = 0;
	Blank str[20][20];

	void Input();
	void Solve();

	size_t GetCount();
};

size_t main()
{
	size_t count;
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

void Soluter::Input()
{
	std::cin >> height >> totalWidth;
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < totalWidth; x++)
		{
			char ch;
			std::cin >> ch;
			if (ch == '#')
			{
				str[x][y] = Blank::BLOCK;
			}
			else
			{
				str[x][y] = Blank::EMPTY;
				emptyCount++;
			}
		}
	}
}

void Soluter::Solve()
{
	if (emptyCount % 3 == 0)
	{
		std::cout << GetCount() << '\n';
	}
	else
	{
		std::cout << 0 << '\n';
	}
}

size_t Soluter::GetCount()
{
	// FindEmptyPos
	size_t emptyX;
	size_t emptyY;
	bool isEmptyPosFound = false;
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < totalWidth; x++)
		{
			if (str[x][y] == Blank::EMPTY)
			{
				emptyX = x;
				emptyY = y;
				isEmptyPosFound = true;
				break;
			}
		}
		if (isEmptyPosFound)
		{
			break;
		}
	}
	if (!isEmptyPosFound)
	{
		return 1;
	}


	// Check_CanPushShape, Counting
	size_t count = 0;
	for (size_t type = 0; type < 4; type++)
	{
		bool canPushShape = true;
		for (size_t posNum = 0; posNum < 3; posNum++)
		{
			size_t x = emptyX + offset[type][posNum].x;
			size_t y = emptyY + offset[type][posNum].y;
			if (x < 0 || y < 0 || x >= totalWidth || y >= height || str[x][y] == Blank::BLOCK)
			{
				canPushShape = false;
				break;
			}
		}

		if (canPushShape)
		{
			for (size_t posNum = 0; posNum < 3; posNum++)
			{
				size_t x = emptyX + offset[type][posNum].x;
				size_t y = emptyY + offset[type][posNum].y;
				str[x][y] = Blank::BLOCK;
			}

			count += GetCount();

			for (size_t posNum = 0; posNum < 3; posNum++)
			{
				size_t x = emptyX + offset[type][posNum].x;
				size_t y = emptyY + offset[type][posNum].y;
				str[x][y] = Blank::EMPTY;
			}
		}
	}
	return count;
}
