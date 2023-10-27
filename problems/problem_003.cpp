/**
* Problem 3
* The prime factors of 13195 are 5, 7, 13 and 29.
* What is the largest prime factor of the number 600851475143 ?
*/

#include "problems.h"
#include "utilities.h"




void PE::problem_003()
{
	const unsigned long long value = 600851475143;
	unsigned long long largest_prime_factor = 0;

	if ( is_prime( value ) )
	{
		largest_prime_factor = value;
	}

	if ( largest_prime_factor == 0)
	{
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
	}
	std::cout << "The largest prime factor of " << value << " is:" << largest_prime_factor << std::endl;
	
}