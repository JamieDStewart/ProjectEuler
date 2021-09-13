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
			int reverseVal = 0;
			while (v != 0)
			{
				int units = v % 10;
				reverseVal = reverseVal * 10 + units;
				v /= 10;
			}
			if( val == reverseVal ) result = val;
		}
	}
	printf("The largest palindromic number made from the product of two three digit numbers is: %ui", result);
	return 0;
}