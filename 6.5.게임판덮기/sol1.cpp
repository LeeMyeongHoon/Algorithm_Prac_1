// https://algospot.com/judge/problem/read/BOARDCOVER
//#define sol1;
#ifdef sol1

#include <vector>

const size_t coverType[4][3][2]
=
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(std::vector<std::vector<size_t>>& board, size_t y, size_t x, size_t type, size_t delta)
{
	bool ok = true;
	for (size_t i = 0; i < 3; i++)
	{
		const size_t nx = y + coverType[type][i][0];
		const size_t ny = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
		{
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1)
		{
			ok = false;
		}
	}

	return ok;
}

size_t cover(std::vector<std::vector<size_t>>& board)
{
	size_t y = -1;
	size_t x = -1;
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) // 찾았으면 빠져나간다.
		{
			break;
		}
	}

	if (y == -1)
	{
		return 1;
	}

	size_t ret = 0;
	for (size_t type = 0; type < 4; type++)
	{
		if (set(board, y, x, type, 1))
		{
			ret += cover(board);
		}
		set(board, y, x, type, -1);
	}
	return ret;
}

#endif // sol1
