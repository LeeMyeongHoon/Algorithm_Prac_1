#ifdef sol1
#include <string>
#include <iostream>
#include <algorithm>

void generate(int n, int m, std::string s)
{
	if (n == 0 && m == 0)
	{
		std::cout << s << '\n';
	}

	if (n > 0)
	{
		generate(n - 1, m, s + "-");
		generate(n, m - 1, s + "o");
	}
}

/****************************************************************************************************************************************/

int skip;
void generate2(int n, int m, std::string s)
{
	if (skip < 0)
	{
		return;
	}
	if (n == 0 && m == 0)
	{
		if (skip == 0)
		{
			std::cout << s << '\n';
		}
		else
		{
			--skip;
		}
		return;
	}
	if (n > 0)
	{
		generate2(n - 1, m, s + "-");
	}
	if (m > 0)
	{
		generate2(n, m - 1, s + "o");
	}
}

/****************************************************************************************************************************************/

const int M = 1000000000 + 100;
int bino[201][201];
void calcBino()
{
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++)
	{
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			bino[i][j] = std::min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

void generate3(int n, int m, std::string s)
{
	if (skip < 0)
	{
		return;
	}
	if (n == 0 && m == 0)
	{
		if (skip == 0)
		{
			std::cout << s << '\n';
		}
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip)
	{
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0)
	{
		generate3(n - 1, m, s + "-");
	}
	if (m > 0)
	{
		generate3(n, m - 1, s + "o");
	}
}

/************************************************************************************************************************************/

std::string kth(int n, int m, int skip)
{
	if (n == 0)
	{
		return std::string(m, 'o');
	}
	if (skip < bino[n + m - 1][n - 1])
	{
		return "-" + kth(n - 1, m, skip);
	}
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}
#endif // sol1
