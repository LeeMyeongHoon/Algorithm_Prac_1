// 반복적 동적계획법
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>
#include <algorithm>

static int dp[1000000];
struct Soluter
{
	int num;

	void Input()
	{
		std::cin >> num;
	}

	void Solve()
	{
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= num; i++)
		{
			dp[i] = std::numeric_limits<int>::max();
			if (i % 3 == 0)
			{
				dp[i] = 1 + dp[i / 3];
			}
			if (i % 2 == 0)
			{
				dp[i] = std::min(dp[i], 1 + dp[i / 2]);
			}

			dp[i] = std::min(dp[i], 1 + dp[i - 1]);
		}

		std::cout << dp[num] << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}