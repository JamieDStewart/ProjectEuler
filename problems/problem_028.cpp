/*
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5  spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_028()
{
	timer::start();
	// number square has a pattern end of a ring corner value follows pattern of squares of odd numbers 1, 9, 25, 49, 81
	// for all values above the starting layer the following pattern for summation of corners is true
	// adding corners follows if n^2 is the top corner for that level then pattern of n^2, n^2 -n + 1 , n^2 - 2n + 2 , n^2 - 3n + 3;
	// quadratic formula for summation of corners becomes 4n^2 - 6n + 6
	int64_t current_sum = 1;
	constexpr int64_t upper_bounds = 1002;
	//initial corner value starts at n=3
	for( int64_t n = 3; n < upper_bounds; n+=2 )
	{
		current_sum += 4 * n * n - 6 * n + 6;
	}

	timer::stop();
	return { "28.Number Spiral Diagonals", get_result_string( current_sum ), timer::get_elapsed_seconds() };
}
