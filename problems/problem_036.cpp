/*
 * The decimal number, 585 = 0b1001001001 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base
 * 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */


#include <algorithm>
#include <bitset>
#include <map>

#include "problems.h"
#include "result.h"
#include "timer.h"
#include "utilities.h"

std::string convert_to_base_2_string( const uint32_t value )
{
	std::string binary = std::bitset<32>( value ).to_string();
	//remove leading zeroes
	binary.erase( 0, binary.find_first_not_of( '0' ) );
	return binary;
}

bool is_palindrome( const std::string& string_representation )
{
	std::string copy = string_representation;
	std::ranges::reverse( copy.begin(), copy.end() );
	return string_representation == copy;
}

Result PE::problem_036()
{
	constexpr uint32_t base_10 = 10;
	constexpr uint32_t base_2 = 2;
	timer::start();
	//Limit to first 1 million values.
	constexpr uint32_t upper_limit = 0xF4240;
	uint32_t sum_of_palindromes = {};
	// For numbers up to 1,000,000 palindromes can take the form of:
	// a, aa, aba, abba, abcba, abccba
	// a must be an odd value as leading 0's aren't counted in the palindrome 1, 3, 5, 7, 9
	// b & c follow values 0 -> 9

	// Gather palindromes
	std::vector<uint32_t> palindromes{};
	for( uint32_t a = 1; a < 10; a+= 2 )
	{
		palindromes.push_back( a ); // a
		palindromes.push_back( a * 10 + a ); //aa

		for( uint32_t b = 0; b < 10; ++b )
		{
			palindromes.push_back( a * 100 + b * 10 + a ); //aba
			palindromes.push_back( a * 1000 + + b * 100 + b * 10 + a ); //abba
			for ( uint32_t c = 0; c < 10; ++c )
			{
				palindromes.push_back( a * 10000 + b * 1000 + c * 100 + b * 10 + a ); //abcba
				palindromes.push_back( a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a ); //abccba
			}
		}
	}
	for( const auto& palindrome : palindromes )
	{
		
		if( is_palindrome( convert_to_base_2_string( palindrome ) ) )
		{
			sum_of_palindromes += palindrome;
		}
				
	}
	
	timer::stop();
	return { "36.Double-base Palindromes", get_result_string( sum_of_palindromes ), timer::get_elapsed_seconds() };
}
