/*
 * In the United Kingdom the currency is made up of pounds and pence
 * There are eight coins in general circulation:
 * 1p, 2p, 5p, 10p, 20p, 50p, 1pound, and  2pound
 *
 * It is possible to make 2 pound in the following way:
 *    1x1pound + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
 *
 * How many different ways can 2 pound be made using any number of coins?
 */

#include <vector>

#include "problems.h"
#include "result.h"
#include "timer.h"

Result PE::problem_031()
{
	timer::start();
	std::vector<uint64_t> coin_values{ 1, 2, 5, 10, 20, 50, 100, 200 };
	// How many variations are there to make up each possible coin value. Make use of some dynamic programming
	// Keep a vector of possible combinations this is the number of different coins that can be used to make up to each value
	std::vector<uint64_t> combinations( 201,0 );
	//only one way to make up a value of zero, use no coins.
	combinations[0] = 1;
	// for each coin value work out how many possible ways there are to make each sum
	// how this works if we only have 1p then there is only 1 way to make 1p and 1 way to make 200p by using all 1p coins
	// if we have 1p & 2p coins then there are 2 ways to make 2p, using 2x1p coins or a single 2p coin. This then accumulates up so there
	// are 101 combinations to produce 200p out of those 2 coins. Distinct order isn't important just number of each coin
	// using a vector when we add in a new coin all values equal to and higher than that coins value will have an increased number of combinations
	for( auto coin : coin_values )
	{
		for( uint64_t i = coin; i < 201; ++i )
		{
			combinations[i] += combinations[i - coin];
		}
	}

	timer::stop();
	return { "30.Coin Sums", get_result_string( combinations[200] ), timer::get_elapsed_seconds()};
}
