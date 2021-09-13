/**
* Problem 4
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
* Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <cstdio>
#include <vector>
int main(int argc, char* argv[])
{
	int result = 0;
	int maxValue = 999;
	int minValue = 100;

	for (int i = maxValue; i >= minValue; --i)
	{
		for (int j = i; j >= minValue; --j)
		{
			int val = i * j;
			if (val < result) break;
			int v = val;
			std::vector<int> units;
			while (v)
			{
				units.push_back(v % 10);
				v /= 10;
			}
			int start = 0;
			int end = units.size()-1;
			bool isPalindromic = true;
			for( ;start <= end; ++start, --end )
			{
				if (units[start] == units[end])
				{
					isPalindromic = true;
				}
				else
				{
					isPalindromic = false;
					break;
				}
			}
			if( isPalindromic ) result = val;
		}
	}
	printf("The largest palindromic number made from the product of two three digit numbers is: %ui", result);
	return 0;
}