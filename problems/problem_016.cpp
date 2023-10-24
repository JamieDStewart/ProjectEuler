/**
* Problem 16
* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
*
* What is the sum of the digits of the number 2^1000?
*
*/

#include "problems.h"
#include <numeric>
#include <vector>

void PE::problem_016()
{
	std::cout << "Problem 016" << std::endl;
	//create a vector containing a single value set to 1
	std::vector<int32_t> accumulator(1,1);
	int32_t cycle_count = 1000;
	for ( int i = 0; i < cycle_count; ++i )
	{
		int32_t carry_value = 0;
		//iterate over the vector starting from the end and moving to the front
		for ( auto r_iter = accumulator.rbegin(); r_iter != accumulator.rend(); ++r_iter )
		{
			//double the value contained in cell
			int32_t val = carry_value + ((*r_iter) << 1);
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
	int32_t sum = std::accumulate( accumulator.begin(), accumulator.end(), 0 );

	std::cout << "The value of the sum of components of 2^" << cycle_count << " is: " << sum << std::endl;

}