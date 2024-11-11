
/**
* Problem 1
* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
* Find the sum of all the multiples of 3 or 5 below 1000.
*/


#include "problems.h"
#include "result.h"
#include "timer.h"


Result PE::problem_001()
{
	timer::start();
	uint64_t sum = 0;
	for (uint64_t i = 3; i < 1000; ++i)
	{
		if (!(i % 3) || !(i % 5))
		{
			sum += i;
		}
	}
	timer::stop();

	return { "1.Multiples of 3 or 5", sum, timer::get_elapsed_seconds() };
}
