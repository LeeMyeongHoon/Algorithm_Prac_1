//https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	static const int ALL_STUDENT_COUNT = 9;
	static const int REAL_STUDENT_COUNT = 7;

	int heights[ALL_STUDENT_COUNT];
	std::vector<int> realStudentHeights;
	bool isFinish = false;

	void Input()
	{
		for (int i = 0; i < ALL_STUDENT_COUNT; i++)
		{
			std::cin >> heights[i];
		}

	}

	bool FindAnswer(int student, int sum)
	{
		if (realStudentHeights.size() == REAL_STUDENT_COUNT)
		{
			if (sum == 100)
			{
				return true;
			}
		}

		if (student >= ALL_STUDENT_COUNT || sum > 100)
		{
			return false;
		}

		realStudentHeights.push_back(heights[student]);
		
		if (FindAnswer(student + 1, sum + heights[student]))
		{
			return true;
		}
		realStudentHeights.pop_back();

		if (FindAnswer(student + 1, sum))
		{
			return true;
		}

		return false;
	}

	void Solve()
	{
		FindAnswer(0, 0);

		std::sort(std::begin(realStudentHeights), std::end(realStudentHeights));

		for (auto& realStudentHeight : realStudentHeights)
		{
			std::cout << realStudentHeight << '\n';
		}
	}


};

int main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}