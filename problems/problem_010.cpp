/**
* Problem 10
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
* Find the sum of all the primes below two million.
*/

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

Result PE::problem_010()
{
	timer::start();
	uint64_t sum = 0;
	for (int i = 1; i < 0x1E8480; ++i)
	{
		if (is_prime(i))
		{
			sum += static_cast<uint64_t>(i);
		}
	}
	timer::stop();
	return { "10.Summation of Primes", get_result_string(sum), timer::get_elapsed_seconds() };
	
}