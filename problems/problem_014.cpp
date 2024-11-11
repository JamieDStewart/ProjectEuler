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
#include "result.h"
#include "timer.h"

uint64_t even( uint64_t value )
{
	return value >> 1;
}

uint64_t odd( uint64_t value )
{
	return 3 * value + 1;
}


Result PE::problem_014()
{
	timer::start();
	
	constexpr uint64_t upper_limit = 1000000;
	//two variables to track the sequence max length and the value that caused this max length
	uint64_t max_sequence_length = 0;
	uint64_t sequence_value = 0;

	//iterate over all values from 1 - 1,000,000 to find the one which produces the longest sequence
	for ( uint64_t i = 1; i < upper_limit; ++i )
	{
		uint64_t sequence_length = 1;
		uint64_t val = i;
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
	timer::stop();
	return { "14.Longest Collatz Sequence", sequence_value, timer::get_elapsed_seconds() };
	
}