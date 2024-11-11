/**
* Problem 25
*
* The Fibonacci sequence is defined by the recurrence relation:
*   Fn = Fn-1 + Fn-2 where F1 = 1 and F2 = 1
* Hence the first 12 terms will be: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
* The 12th term F12 is the first term to contain three digits.
*
* What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*
*/



#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

#include <algorithm>



Result PE::problem_025()
{
	timer::start();
	//1000 digits is too many digits to store in an integral variable
	//Implement fibonacci sequence using std::vector containing single units.
	std::vector<std::vector<uint8_t>> fib_sequence( 2 );
	//Fill in the first to values in the Fibonacci sequence F1  = 1, F2 = 1
	fib_sequence[0].push_back( 1 );
	fib_sequence[1].push_back( 1 );
	uint64_t sequence_id = 2;
	uint8_t index = 0;
	
	while( fib_sequence[index].size() < 1000 )
	{
		uint8_t carry_value = 0;
		for ( uint64_t p = 0; p < fib_sequence[0].size(); ++p )
		{
			uint8_t result = fib_sequence[0][p] + fib_sequence[1][p] + carry_value;
			carry_value = result / 10;
			//store result mod 10 back in vector
			result = result % 10;
			fib_sequence[index][p] = result;
		}
		//if we've got a carry left we need to extend the factorial vector
		if ( carry_value != 0 )
		{
			fib_sequence[index].push_back( carry_value % 10 );
			index = (++index % 2);
			fib_sequence[index].push_back( 0 );
		}
		else
		{
			index = (++index % 2);
		}
		sequence_id++;
	}

	timer::stop();
	return { "25.1000-Digit Fibonacci Number", sequence_id, timer::get_elapsed_seconds() };
	
}