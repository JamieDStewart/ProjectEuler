/**
*Problem 5
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <cstdio>

int main(int argc, char* argv[])
{
	//Number must be a multiple of both 19 & 20
	long long baseNumber = 19 * 20;
	long long val = baseNumber;
	while (true)
	{
		long long st = val;
		for (long long i = 1; i <= 20; ++i)
		{
			if (val % i)
			{
				val += baseNumber;
				break;
			}
		}
		if (val == st) break;
	}
	printf("Smallest positive number that is evenly divisible by 1 to 20 is: %lld", val);
	return 0;
}