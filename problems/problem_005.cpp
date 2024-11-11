/**
*Problem 5
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_005()
{
	timer::start();
	//Number must be a multiple of both 19 & 20
	constexpr uint64_t baseNumber = 19 * 20;
	uint64_t val = baseNumber;
	while (true)
	{
		const uint64_t st = val;
		for (uint64_t i = 1; i <= 20; ++i)
		{
			if (val % i)
			{
				val += baseNumber;
				break;
			}
		}
		if (val == st) break;
	}
	timer::stop();
	return { "5.Smallest Multiple", val, timer::get_elapsed_seconds() };
	
	
}