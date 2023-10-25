/**
* Problem 21
* Let d(n) be defined as the sum of proper divisors of n (numbers less than n, which divide evenly into n).
* If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.
* For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
* The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
*
* Evaluate the sum of all the amicable numbers under 10,000.
*/

#include "problems.h"
#include "utilities.h"

#include <numeric>
#include <vector>


void PE::problem_021()
{
	std::cout << "Problem 021" << std::endl;
	//create a vector to store all factor sums d(n)
	std::vector<uint32_t> factor_sums( 10001, 0 );
	uint32_t amicable_sum = 0;

	for( uint32_t i = 1; i < factor_sums.size(); ++i )
	{
		//set factor sum total to zero
		uint32_t sum_factors = 1;
		// start testing factor with value 2 or 3 (1 is a factor of all numbers)
		uint32_t factor = (i%2 == 0)? 2: 3;
		//Only need to test up to the square root of a number to reduce range of tests
		const auto max_factor = static_cast<uint32_t>(sqrt( i ));
		while ( factor <= max_factor )
		{
			// if mod and triangle number is zero then factor is a factor of this number increment factor count
			if ( i % factor == 0 )
			{
				//if number / factor is not equal to factor then a corresponding value large than the square root is a factor
				sum_factors += factor;
				//get the larger factor
				const uint32_t larger_factor = i / factor;
				if( factor != larger_factor ) //dont add the larger factor if this is a square of the number
				{
					sum_factors += larger_factor;
				}

			}
			factor++;
		}
		factor_sums[i] = sum_factors;
		
		if( sum_factors < factor_sums.size() && sum_factors != i && factor_sums[sum_factors] == i )
		{
			amicable_sum += i + sum_factors;
		}

	}

	std::cout << "The sum of the amicable numbers under " << factor_sums.size()-1 << " is: " << amicable_sum <<std::endl;
}