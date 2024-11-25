/*
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly
 * believe that 49/98 = 4/8 which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one in value,
 * and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_033()
{
	timer::start();
	int32_t accumulated_numerator_product{1};
	int32_t accumulated_denominator_product{1};

	// We're looking for all fractions num/dom that allow cancelling of common values to produce the same value.
	// only test ones unit of denominator with tens digit of numerator as other values produce values greater than 1
	for ( auto cancelled_out_value = 1; cancelled_out_value <= 9; ++cancelled_out_value )
	{
		for ( auto denominator = 1; denominator < cancelled_out_value; ++denominator )
		{
			for ( auto numerator = 1; numerator < denominator; ++numerator )
			{
				const int32_t full_numerator{ numerator * 10 + cancelled_out_value };
				const int32_t full_denominator{ cancelled_out_value * 10 + denominator };
				
				if ( full_numerator * denominator == full_denominator * numerator )
				{
						accumulated_numerator_product *= full_numerator;
						accumulated_denominator_product *= full_denominator;
				}
			}
		}
	}
	//get the greatest common denominator
	const int32_t gcd = std::gcd( accumulated_numerator_product, accumulated_denominator_product );
	accumulated_denominator_product /= gcd;

	timer::stop();
	return { "33.Digit Cancelling Fractions", get_result_string( accumulated_denominator_product ), timer::get_elapsed_seconds() };
}
