#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

bool isFinished(const vector<string>& board, char turn);

// 보드판을 3진수 형태로 저장
int bijection(const vector<string>& board)
{
	int ret = 0;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			ret *= 3;	// 3진수에서의 left shift 연산
			if (board[y][x] == 'o')
			{
				ret += 1;
			}
			else if (board[y][x] == 'x')
			{
				ret += 2;
			}
			/*else
			{
				ret += 0;
			}*/
		}
	}
	return ret;
}

int cache[19683];

int canWin(vector<string>& board, char turn)
{
	if (isFinished(board, 'o' + 'x' - turn))
	{
		return -1;
	}

	int& ret = cache[bijection(board)];
	if (ret != -2)
	{
		return ret;
	}

	int minValue = 2;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] == '.')
			{
				board[y][x] = turn;
				minValue = std::min(minValue, canWin(board, 'o' + 'x' - turn);
				board[y][x] = '.';
			}
		}
	}

	if (minValue == 2 || minValue == 0)
	{
		return ret = 0;
	}
	else
	{
		return ret -= minValue;
	}
}