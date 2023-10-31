/**
* Problem 24
*
* A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
* If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
* The lexicographic permutations of 0, 1 and 2 are: 012   021   102   120   201   210
*
* What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?*
*/



#include "problems.h"
#include "utilities.h"

#include <algorithm>
#include <string>


//solve via manual permutation
void permute( std::vector<std::string>& permutations, const uint32_t max_permutations, std::string input, const std::string& output )
{
	// When size of the input string is 0 this is a permutation 
	if ( input.empty() )
	{
		//output contains one full permutation
		permutations.push_back(output);
		return;
	}
	//iterate over all values in string
	for ( int i = 0; i < input.size(); i++ )
	{
		// call permute recursively
		// Remove first character from str and add it to out
		permute( permutations, max_permutations, input.substr( 1 ), output + input[0] );

		if ( permutations.size() == max_permutations )
		{
			return;
		}
		// Rotate string 
		std::rotate( input.begin(), input.begin() + 1, input.end() );
	}
}

void PE::problem_024()
{
	std::cout << "Problem 024" << std::endl;
	const std::string permutation_string = "0123456789";
	start_timer();
	std::vector<std::string> permutations = {};
	//solve through manual permutations
	permute( permutations, 1100000u, permutation_string, "" );
	std::sort( permutations.begin(), permutations.end() );
	stop_timer();
	std::cout << "=================== Manual Calculation ============================" << std::endl;
	std::cout << "The millionth permutation of 0123456789 is: " << permutations[999999] << std::endl;
	std::cout << "Elapsed time: " << get_elapsed_time() << std::endl;

	//This problem could be solved using std::next_permutation
	start_timer();
	char permutation[11];
	strcpy_s( permutation, 11, permutation_string.c_str());
	for( uint32_t i = 1; i < 1000000; ++i )
	{
		std::next_permutation( permutation, permutation+10 );
	}
	stop_timer();
	std::cout << "=================== Using std::next_permutation ============================" << std::endl;
	std::cout << "The millionth permutation of 0123456789 is: " << permutation << std::endl;
	std::cout << "Elapsed time: " << get_elapsed_time() << std::endl;

	//Calculate using factorial representation
	start_timer();
	uint32_t permutation_count = 999999;
	std::vector<uint32_t> factorial_representation = {};

	for(uint32_t divisor = 1;  permutation_count != 0; ++divisor )
	{
		factorial_representation.push_back( permutation_count % divisor );
		permutation_count /= divisor;
	}
	std::string perm = permutation_string;
	std::string millionth_perm = {};
	while( !perm.empty() )
	{
		for( auto iter = factorial_representation.rbegin(); iter != factorial_representation.rend(); ++iter )
		{
			const uint32_t index = *iter;
			millionth_perm += perm.at(index  );
			perm.erase( index, 1 );			
		}
	}
	stop_timer();
	std::cout << "=================== Using Factorial Number System ============================" << std::endl;
	std::cout << "The millionth permutation of 0123456789 is: " << millionth_perm << std::endl;
	std::cout << "Elapsed time: " << get_elapsed_time() << std::endl;
}