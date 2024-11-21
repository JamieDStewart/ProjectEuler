/**
* Problem 4
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
* Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_004()
{
	timer::start();

	uint64_t result = 0;
	constexpr uint64_t maxValue = 999;
	constexpr uint64_t minValue = 100;

	for ( uint64_t i = maxValue; i >= minValue; --i)
	{
		for ( uint64_t j = i; j >= minValue; --j)
		{
			const uint64_t val = i * j;
			if (val < result) break;
			uint64_t v = val;
			uint64_t reverseVal = 0;
			while (v != 0)
			{
				const uint64_t units = v % 10;
				reverseVal = reverseVal * 10 + units;
				v /= 10;
			}
			if( val == reverseVal ) result = val;
		}
	}
	timer::stop();
	return { "4.Largest Palindrome Product", get_result_string(result), timer::get_elapsed_seconds() };
	

}