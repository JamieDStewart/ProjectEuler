/*
 * Euler discovered the remarkable quadratic formula: n^2 + n + 41
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39.
 * However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when
 * n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 *
 * The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values 0 <= n <= 79.
 * The product of the coefficients, -79 and 1601, is -126479.
 * Considering quadratics of the form: n^2 + an + b,
 * where |a|< 1000 and |b| <= 1000 where |n| is the modulus/absolute value of n
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number
 * of primes for consecutive values of n, starting with n = 0.
 */

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"


Result PE::problem_027()
{
	timer::start();
	int64_t product_of_coefficients{};
	//set up initial values
	int64_t limit{ 1000 };
	
	
	int64_t result{ 0 };
	int64_t max_sequence_length{ 0 };
	//loop over all values and assess if value calculated is prime
	for( int64_t a{ -limit }; a < limit; ++a )
	{
		for( int64_t b{ -limit }; b <= limit; ++b )
		{
			int64_t n{ 0 };
			while ( is_prime( n * n + a * n + b ) )
			{
				++n;
			}
			
			if( n != 0 && n > max_sequence_length)
			{
				max_sequence_length = n;
				//calculate product of coefficients
				product_of_coefficients = a*b;
			}
		}
	}
	timer::stop();
	return { "27.Quadratic Primes", get_result_string( product_of_coefficients ), timer::get_elapsed_seconds() };
}
