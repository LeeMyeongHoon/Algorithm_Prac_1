//// https://algospot.com/judge/problem/read/PACKING
//
//// 최대 절박도만 구하는 풀이
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <limits>
//#include <string>
//
//
//struct Soluter
//{
//	int itemCount;
//	int capacity;
//	std::vector<std::string> names;
//	std::vector<int> volumes;
//	std::vector<int> values;
//
//	void Input()
//	{
//		std::cin >> itemCount >> capacity;
//		names.assign(itemCount, "");
//		volumes.assign(itemCount, 0);
//		values.assign(itemCount, 0);
//
//		for (int i = 0; i < itemCount; i++)
//		{
//			std::cin >> names[i] >> volumes[i] >> values[i];
//		}
//	}
//
//	int GetMaxSumOfValues()
//	{
//	}
//
//	void Solve()
//	{
//	}
//};
//
//int main()
//{
//	int count;
//	std::cin >> count;
//	std::vector<Soluter> soluters(count);
//
//	for (auto& soluter : soluters)
//	{
//		soluter.Input();
//	}
//
//	for (auto& soluter : soluters)
//	{
//		soluter.Solve();
//	}
//
//	return 0;
//}