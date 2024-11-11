/**
* Problem 3
* The prime factors of 13195 are 5, 7, 13 and 29.
* What is the largest prime factor of the number 600851475143 ?
*/

#include "problems.h"
#include "utilities.h"
#include "result.h"
#include "timer.h"

Result PE::problem_003()
{
	timer::start();
	constexpr uint64_t value = 600851475143;
	uint64_t largest_prime_factor = 0;

	if ( is_prime( value ) )
	{
		largest_prime_factor = value;
		timer::stop();
		return { "Largest Prime Factor", largest_prime_factor, timer::get_elapsed_seconds() };
	}
	//If the value isn't a prime itself
	unsigned long long max_value = value;

	for (unsigned long long i = 2; i <= max_value; ++i)
	{
		if (!(max_value % i))
		{
			if ( is_prime(i) && i > largest_prime_factor )
			{
				max_value = max_value / i;
				largest_prime_factor = i;
			}
		}
	}
	timer::stop();
	return { "3.Largest Prime Factor", largest_prime_factor, timer::get_elapsed_seconds() };
	
}