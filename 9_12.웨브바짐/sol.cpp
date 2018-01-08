#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/****************************************************************************************************************************************/

std::string e;
std::string digits;
int n, m;
void generate(std::string price, bool taken[15])
{
	if (price.size() == n)
	{
		if (price < e)
		{
			std::cout << price << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!taken[i] && (i == 0 || digits[i - 1] != digits[i] || taken[i - 1]))
		{
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}