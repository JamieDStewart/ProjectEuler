/*
 * A unit fraction contains 1 in the numerator.
 * The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *    1/2 = 0.5
 *	  1/3 = 0.(3)
 *	  1/4 = 0.25
 *	  1/5 = 0.2
 *	  1/6 = 0.1(6)
 *	  1/7 = 0.(142857)
 *	  1/8 = 0.125
 *	  1/9 = 0.(1)
 *	  1/10 = 0.1
 *	  Where 0.1(6) means 0.16666...., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 *	  Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include "problems.h"
#include "result.h"
#include "timer.h"


Result PE::problem_026()
{
	timer::start();
	constexpr uint32_t upper_limit{ 1000 };

	uint64_t denominator = {};
	uint64_t repeat_length = {};
	
	for( int i = 3; i < upper_limit; i+=2 )
	{
		uint64_t counter = 1;
		uint64_t mod_value = 10 % i;
		if ( mod_value == 0 ) continue;
		
		uint64_t j = upper_limit;
		for( ; j > 0 && mod_value != 1; --j )
		{
			mod_value = (mod_value * 10) % i;
			counter++;			
		}
		if( counter > repeat_length && j > 1 )
		{
			repeat_length = counter;
			denominator = i;
		}		
	}

	timer::stop();
	return { "26.Reciprocal Cycles", denominator, timer::get_elapsed_seconds() };
}