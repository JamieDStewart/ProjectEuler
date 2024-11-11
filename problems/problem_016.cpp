/**
* Problem 16
* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
*
* What is the sum of the digits of the number 2^1000?
*
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#include <numeric>
#include <vector>

Result PE::problem_016()
{
	timer::start();
	//create a vector containing a single value set to 1
	std::vector<uint64_t> accumulator(1,1);
	constexpr uint64_t cycle_count = 1000;
	for ( int i = 0; i < cycle_count; ++i )
	{
		uint64_t carry_value = 0;
		//iterate over the vector starting from the end and moving to the front
		for ( auto r_iter = accumulator.rbegin(); r_iter != accumulator.rend(); ++r_iter )
		{
			//double the value contained in cell
			uint64_t val = carry_value + ((*r_iter) << 1);
			//If the size of val is greater than 10 then turn on the carry flag.
			carry_value = (val >= 10) ? 1 : 0;
			//mod val to get the value in the units position
			val = val % 10;
			*r_iter = val;			
		}
		if ( carry_value == 1 )
		{
			accumulator.insert( accumulator.begin(), carry_value );
		}
	}

	//accumulate each element in the array
	const uint64_t sum = std::accumulate( accumulator.begin(), accumulator.end(), 0ULL );
	timer::stop();
	return { "16.Power Digit Sum", sum, timer::get_elapsed_seconds() };

}