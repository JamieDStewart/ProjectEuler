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
		std::vector<uint32_t> factors = get_factors( i );
		//set factor sum total to zero
		const uint32_t sum_factors = static_cast<uint32_t>(std::accumulate( factors.begin(), factors.end(), 0u ));
		
		factor_sums[i] = sum_factors;
		
		if( sum_factors < factor_sums.size() && sum_factors != i && factor_sums[sum_factors] == i )
		{
			amicable_sum += i + sum_factors;
		}

	}

	std::cout << "The sum of the amicable numbers under " << factor_sums.size()-1 << " is: " << amicable_sum <<std::endl;
}