/**
* Problem 23
*
* A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example,
* the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
*
* A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n
*
* As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two
* abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum
* of two abundant numbers.
* However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be
* expressed as the sum of two abundant numbers is less than this limit.
*
* Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
* 
*/



#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

#include <numeric>
#include <vector>

struct name_score
{
	std::string name;
	int32_t score;
};

Result PE::problem_023()
{
	timer::start();
	//get all abundant numbers below 28123
	constexpr uint32_t upper_limit = 28123;
	std::vector<uint32_t> abundant_numbers;
	for( uint32_t i = 1; i < upper_limit; ++i )
	{
		const auto factors = get_factors( i );
		const uint32_t factor_sum = std::accumulate( factors.begin(), factors.end(), 0u );
		if( factor_sum > i )
		{
			abundant_numbers.push_back( i );
		}
	}
	//iterating across the abundant numbers array and summing them will produce all abundant value sums store this in an array and then sum those values that are not the
	//product of two abundant numbers
	bool abundant_products[upper_limit] = { false };
	const uint64_t abundant_count = abundant_numbers.size();
	for( uint32_t i = 0; i < abundant_count; ++i )
	{
		for ( uint32_t j = i; j < abundant_count; ++j )
		{
			uint64_t result = abundant_numbers[i] + abundant_numbers[j];
			if ( result < upper_limit )
			{
				abundant_products[result] = true;
			}
		}
	}
	//loop over the array of abundant products and sum the index value of all non abundant values.
	uint64_t sum_of_non_abundant{0};
	for( uint64_t n = 1; n < upper_limit; ++n )
	{
		if( !abundant_products[n] )
		{
			sum_of_non_abundant += n;
		}
	}
		
	timer::stop();
	return { "23.Non-Abundant Numbers", get_result_string( sum_of_non_abundant), timer::get_elapsed_seconds() };
	
}
