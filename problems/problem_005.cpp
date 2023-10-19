/**
*Problem 5
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "problems.h"

void PE::problem_005()
{
	//Number must be a multiple of both 19 & 20
	constexpr long long baseNumber = 19 * 20;
	long long val = baseNumber;
	while (true)
	{
		const long long st = val;
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
	std::cout << "Smallest positive number that is evenly divisible by 1 to 20 is: " << val << std::endl;
	
}