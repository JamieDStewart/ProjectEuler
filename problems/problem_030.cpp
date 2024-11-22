/*
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *  1634 = 1^4 + 6^4 + 3^4 + 4^4
 *	8208 = 8^4 + 2^4 + 0^4 + 8^4
 *	9474 = 9^4 + 4^4 + 7^4 + 4^4
 *
 *	As 1^4 is not a sum it is not included.
 *	The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 *	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <numeric>
#include <set>

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_030()
{
	timer::start();
	// There is an upper cap to the numbers to check as a maximum value as each unit increases
	// 1 * 9^5, 2 * 9^5, 3 * 9^5, 4 * 9^5, 5 * 9^5, 6 * 9^5, 7 * 9^5...
	// At 7 * 9^5 (413343) all results have fewer than 7 digits, this continues up for numbers with more units.
	uint64_t sums_of_fifths{0};

	for( uint64_t a = 2; a < 999999; ++a )
	{
		uint64_t num{ a };
		uint64_t component_sum{};
		while( num > 0 )
		{
			component_sum += static_cast<uint64_t>(pow( num % 10, 5 ));
			num /= 10;
		}
		if( component_sum == a )
		{
			sums_of_fifths += a;
		}		
	}
	timer::stop();
	return { "30.Digit Fifth Powers", get_result_string( sums_of_fifths), timer::get_elapsed_seconds() };
}
