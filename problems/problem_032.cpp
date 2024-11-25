/*
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n
 * exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 * The product 7254 is unusual, as the identity, 39 x 186 = 7254 containing multiplicand, multiplier, and product is
 * 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */

#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_032()
{
	timer::start();
	// This question is a permutation question - we have numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9 } we need to find permutations of these numbers where
	// a x b = c. The number of permutations of { 1, 2, 3, 4, 5, 6, 7, 8, 9 } is fewer than iterating over the numbers 0 - 10000 in a brute force
	// nested loop by at least 2/3.

	std::vector< uint32_t > digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::set< uint32_t> pandigital_products{};

	do
	{
		//To satisfy this problem a must be less than 100 and b contain no more than 4 digits to produce a 4 digit product
		for( auto length_a = 1; length_a < 3; ++length_a )
		{
			for( auto length_b = 3; length_b < 5; length_b++ )
			{
				//get the value for a from the permutation
				uint32_t a{};
				for( auto i = 0; i < length_a; ++i )
				{
					a *= 10;
					a += digits[i];
				}
				//Get the value for b
				uint32_t b{};
				for ( auto i = length_a; i < length_a + length_b; ++i )
				{
					b *= 10;
					b += digits[i];
				}

				//Get the value for c
				uint32_t c{};
				for ( auto i = length_a + length_b; i < digits.size(); ++i )
				{
					c *= 10;
					c += digits[i];
				}

				if( a * b == c )
				{
					pandigital_products.emplace( c );
				}
			}
		}
	}
	while ( std::ranges::next_permutation( digits.begin(), digits.end() ).found );

	const uint32_t pandigital_sum = std::accumulate( pandigital_products.begin(), pandigital_products.end(), 0U );
	timer::stop();
	return { "32.Pandigital Products", get_result_string( pandigital_sum ), timer::get_elapsed_seconds() };
}
