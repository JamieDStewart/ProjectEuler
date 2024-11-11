/**
* Problem 9
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
* a^2 + b^2 = c^2
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_009()
{
	timer::start();
	uint64_t product = 0;
	constexpr uint64_t sum = 1000;
	for ( uint64_t a = 1; a < sum; ++a)
	{
		for ( uint64_t b = a+1; b < sum; ++b)
		{
			const uint64_t c = sum - a - b;
			if ((a * a + b * b) == (c * c))
			{
				product = a * b * c;
			}
		}
	}
	timer::stop();
	return { "9.Special Pythagorean Triplet", product, timer::get_elapsed_seconds() };
	
}