/*
 * The number,197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100:
 *     2, 3, 5, 7, 13, 17, 31, 37, 71, 73, 79, and, 97.
 *
 * How many circular primes are there below one million?
 */


#include <algorithm>
#include <map>

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

Result PE::problem_035()
{
	timer::start();
	//To start gather up all prime numbers less than 1,000,000
	std::map<uint32_t, std::string> prime_numbers{};
	//from the question we know there are 13 circular primes below 100
	uint32_t circular_primes_count = 13;
	for( auto i = 100; i < 0xF4240; ++i )
	{
		if( is_prime(i) )
		{
			//circular primes cannot contain even numbers or fives
			bool contains_even_number = false;
			uint32_t val = i;
			do
			{
				if( val % 2 == 0 || val % 5 == 0 )
				{
					contains_even_number = true;
					break;
				}
				val /= 10;
			}
			while ( val != 0 );

			if( !contains_even_number )	prime_numbers[i] = std::to_string(i);
		}
	}
	//Go over each item and find out if it's permutation is in the dictionary if all permutations are present then this is a circular prime
	for( auto i = prime_numbers.begin(); i != prime_numbers.end(); ++i )
	{
		std::string prime = i->second;
		bool is_circular = true;
		for ( auto j = 1; j < prime.length(); ++j )
		{
			//rotate the string and find that permutation in the dictionary
			std::ranges::rotate( prime.begin(), prime.begin() + 1, prime.end() );
			if( auto locate = prime_numbers.find(std::stoi(prime)); locate == prime_numbers.end() )
			{
				is_circular = false;
				break;
			}
		}
		if( is_circular )
		{
			circular_primes_count++;
		}

	}
	timer::stop();
	return { "35.Circular Primes", get_result_string( circular_primes_count ), timer::get_elapsed_seconds() };
}
