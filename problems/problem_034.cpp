/*
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * Note: As 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <vector>

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

Result PE::problem_034()
{
	timer::start();
	//Upper limit is an 7-digit number as 8 * 9! = 2903040 this has only 7 digits and cannot sum to 8-digits.
	//construct a factorial table of digits 0 through 9
	const std::vector<uint64_t> factorial{ 1ULL, 1ULL, 2ULL, get_factorial( 3 ),
		get_factorial( 4 ), get_factorial( 5 ), get_factorial( 6 ),
		get_factorial( 7 ), get_factorial( 8 ), get_factorial( 9 ) };

	const uint64_t upper_bound = 7 * get_factorial( 9 );
	uint64_t digit_factorial_accumulation{};
	for( uint64_t i = 3; i < upper_bound; ++i )
	{
		uint64_t value = i;
		uint64_t factorial_sum_of_components{};
		do
		{
			factorial_sum_of_components += factorial[value % 10];
			value /= 10;
		}
		while ( value != 0 );

		if( i == factorial_sum_of_components ) // if the sum of factorials is the original value
		{
			digit_factorial_accumulation += factorial_sum_of_components;
		}

	}
	timer::stop();
	return { "34.Digit Factorials", get_result_string( digit_factorial_accumulation ), timer::get_elapsed_seconds() };
}
