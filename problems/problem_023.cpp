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
#include "utilities.h"

#include <algorithm>
#include <numeric>
#include <vector>

struct name_score
{
	std::string name;
	int32_t score;
};

void PE::problem_023()
{
	std::cout << "Problem 023" << std::endl;
	//get all abundant numbers below 28123
	uint32_t upper_limit = 28123;
	std::vector<uint32_t> abundant_numbers;
	for( uint32_t i = 12; i < upper_limit; ++i )
	{
		const auto factors = get_factors( i );
		const uint32_t factor_sum = std::accumulate( factors.begin(), factors.end(), 0u );
		if( factor_sum > i )
		{
			abundant_numbers.push_back( i );
		}
	}
	std::cout << "Number of abundant numbers: " << abundant_numbers.size() << std::endl;
	//first numbers smaller than 24 are all not sum of abundant numbers so accumulate their values
	constexpr uint32_t sum_of_values_less_than_24 = 276;
	uint32_t sum_of_non_abundants = sum_of_values_less_than_24;
	//go through numbers larger then 24 up to half way through the list of abundant numbers to find out if number is possible product of two abundant numbers
	for( uint32_t number = 24; number < upper_limit; number++ )
	{
		//only need to go half way as would have found opposite half by then
		bool is_abundant_sum = false;
		const uint32_t half_number = number >> 1;
		//find iterator location to search up to
		for ( auto abundant_number = abundant_numbers.begin(); *abundant_number <= half_number; ++abundant_number )
		{
			uint32_t number_sub_abundant = number - (*abundant_number);
			// Use find to see if the opposite number is contained in the list of abundant numbers.
			if ( std::find( abundant_number, abundant_numbers.end(), number_sub_abundant ) != abundant_numbers.end() )
			{				
				is_abundant_sum = true;
				break;
			}

		}
		if( !is_abundant_sum )
		{
			
			sum_of_non_abundants += number;
		}
		
	}
	std::cout << "Sum of non abundant composed numbers: " << sum_of_non_abundants << std::endl;

}
