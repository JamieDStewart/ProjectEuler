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
	unsigned long long largestPrimeFactor = 0;
	if (is_prime(value)) largestPrimeFactor = value;
	if (largestPrimeFactor == 0)
	{
		unsigned long long maxValue = value;

		for (unsigned long long i = 2; i <= maxValue; ++i)
		{
			if (!(maxValue % i))
			{
				if ( is_prime(i) && i > largestPrimeFactor)
				{
					maxValue = maxValue / i;
					largestPrimeFactor = i;
				}
			}
		}
	}
	std::cout << "The largest prime factor of " << value << " is:" << largestPrimeFactor << std::endl;
	
}