// https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <vector>

enum class Blank
{
	BLOCK, EMPTY
};

struct Pos2D
{
	int x, y;
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

	int height;
	int width;
	int emptyCount = 0;
	Blank str[20][20];

	void Input();
	void Solve();

	int GetCount();
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

void Soluter::Input()
{
	std::cin >> height >> width;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
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

int Soluter::GetCount()
{
	// FindEmptyPos
	int emptyX;
	int emptyY;
	bool isEmptyPosFound = false;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
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
	int count = 0;
	for (int type = 0; type < 4; type++)
	{
		bool canPushShape = true;
		for (int posNum = 0; posNum < 3; posNum++)
		{
			int x = emptyX + offset[type][posNum].x;
			int y = emptyY + offset[type][posNum].y;
			if (x < 0 || y < 0 || x >= width || y >= height || str[x][y] == Blank::BLOCK)
			{
				canPushShape = false;
				break;
			}
		}

		if (canPushShape)
		{
			for (int posNum = 0; posNum < 3; posNum++)
			{
				int x = emptyX + offset[type][posNum].x;
				int y = emptyY + offset[type][posNum].y;
				str[x][y] = Blank::BLOCK;
			}

			count += GetCount();

			for (int posNum = 0; posNum < 3; posNum++)
			{
				int x = emptyX + offset[type][posNum].x;
				int y = emptyY + offset[type][posNum].y;
				str[x][y] = Blank::EMPTY;
			}
		}
	}
	return count;
}
