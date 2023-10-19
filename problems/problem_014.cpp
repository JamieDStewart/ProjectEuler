/**
* Problem 14
* The following iterative sequence is defined for the set of positive integers
*   n -> n/2 (n is even)
*	n-> 3n + 1 (n is odd)
* Using the rule above and starting with 13 produces the following sequence:
*   13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
*
* It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved
* yet (Collatz Problem), it is thought that all starting numbers finish as 1.
*
* Which starting number, under 1 million, produces the longest chain?
*
* Note: once the chain starts the terms are allowed to go above one million*
*/
#include "problems.h"

uint32_t even( uint32_t value )
{
	return value >> 1;
}

uint32_t odd( uint32_t value )
{
	return 3 * value + 1;
}


void PE::problem_014()
{
	std::cout << "Problem 014" << std::endl;
	constexpr uint32_t upper_limit = 1000000;
	//two variables to track the sequence max length and the value that caused this max length
	uint32_t max_sequence_length = 0;
	uint32_t sequence_value = 0;

	//iterate over all values from 1 - 1,000,000 to find the one which produces the longest sequence
	for ( uint32_t i = 1; i < upper_limit; ++i )
	{
		uint32_t sequence_length = 1;
		uint32_t val = i;
		//sequence has ended when value reaches 1
		while ( val != 1 )
		{
			//execute even or odd function based on value of number and increment sequence length
			val = ((val & 1) == 0) ? even( val ) : odd( val );
			sequence_length++;
		}
		//sequence has finished, if it was longer than the previous one then update length and value trackers
		if( sequence_length > max_sequence_length )
		{
			max_sequence_length = sequence_length;
			sequence_value = i;
		}
	}
	std::cout << "Value: " << sequence_value << " produces a sequence length of: " << max_sequence_length << std::endl;

}