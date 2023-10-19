/**
* Problem 10
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
* Find the sum of all the primes below two million.
*/

#include "problems.h"
#include "utilities.h"

void PE::problem_010()
{
	unsigned long long sum = 0;
	for (int i = 1; i < 0x1E8480; ++i)
	{
		if (is_prime(i))
		{
			sum += static_cast<unsigned long long>(i);
		}
	}

	std::cout << "Sum of primes below 2 million is: " << sum << std::endl;
}