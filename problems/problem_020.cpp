/**
* Problem 20
*  n! means n * (n-1) * ... * 3 * 2 * 1.
*  For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 362880,
*  and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27
*
*  Find the sum of the digits in the number 100!.
*/

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

#include <numeric>
#include <vector>


Result PE::problem_020()
{
	timer::start();
	//Factorial of 100 is too large to make use of integers
	//std::cout << "100! is: " << factorial(100) << std::endl;

	//Use a vector to hold individual unit integers set with single value starting at 1
	std::vector<int32_t> factorial(1,1);

	int32_t factorial_value = 100;
	//for loop to go over each digit until factorial value is reached
	for( int32_t i = 1; i <= factorial_value; ++i )
	{
		int32_t carry_value = 0;
		for( auto unit = factorial.begin(); unit != factorial.end(); ++unit )
		{
			int32_t result = (*unit) * i + carry_value;
			carry_value = result / 10;
			//store result mod 10 back in vector
			*unit = result % 10;			
		}
		//if we've got a carry left we need to extend the factorial vector
		while( carry_value != 0 )
		{
			factorial.push_back( carry_value % 10 );
			carry_value /= 10;
		}
	}

	const uint64_t sum = std::accumulate( factorial.begin(), factorial.end(), 0 );

	timer::stop();
	return { "20.Factorial Digit Sum", sum, timer::get_elapsed_seconds() };	

}