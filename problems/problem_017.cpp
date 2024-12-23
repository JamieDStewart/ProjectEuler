/**
* Problem 17
* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are
* 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
*
* If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
*
* NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters
* and 115 (one hundred and fifteen) contains 20 letters.
*
* The use of "and" when writing out numbers is in compliance with British usage.
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#define length(x) sizeof(x)-1

Result PE::problem_017()
{
	timer::start();
	constexpr uint64_t upper_limit = 1000;
	//const expressions for number of letters in a word
	constexpr uint64_t hundred = length ("hundred");
	constexpr uint64_t thousand = length( "thousand" );
	constexpr uint64_t _and = length( "and" );
	constexpr uint64_t teens[10] = { length( "ten" ), length( "eleven" ), length( "twelve" ), length( "thirteen" ), length( "fourteen" ), length( "fifteen" ),
								  length( "sixteen" ), length( "seventeen" ), length( "eighteen" ), length( "nineteen" ) };
	constexpr uint64_t tens[8] = { length( "twenty" ), length( "thirty" ), length( "forty" ), length( "fifty" ), length( "sixty" ), length( "seventy" ),
								  length( "eighty" ), length( "ninety" ) };
	constexpr uint64_t units[9] = { length( "one" ), length( "two" ), length( "three" ), length( "four" ), length( "five" ), length( "six" ), length( "seven" ), length( "eight" ), length( "nine" ) };

	uint64_t letter_count = 0;
	//How many hundreds are there? Upper_limit / 100 sub first 100
	constexpr uint64_t hundred_count = upper_limit / 100;
	if ( hundred_count > 0 )
	{
		constexpr uint64_t hundred_count_sub_1 = hundred_count - 1;
		letter_count = (hundred_count_sub_1 * 100) * hundred;
		//how many 'ands'
		// and occurs in every number above 100 minus every whole hundred (200,300,etc)
		letter_count += _and * hundred_count_sub_1 * 100 - (_and * hundred_count_sub_1);
	}
	//how many thousands
	constexpr uint64_t thousands = upper_limit / 1000;
	for ( uint64_t i = 0; i < thousands; ++i )
	{
		//only one "one thousand"
		letter_count += units[i] + thousand;
	}
	//Tens occur ten times each per hundred
	uint64_t tens_count = 0;
	for ( const auto ten : tens )
	{
		tens_count += ten * hundred_count * 10;
	}
	letter_count += tens_count;

	//teens occur ten times once per hundred
	uint64_t teens_count = 0;
	for ( const auto teen : teens )
	{
		teens_count += teen * hundred_count;
	}
	letter_count += teens_count;
	//for 1-99 each unit is written out 9 times per hundred, plus 100 times for the leading hundred value
	uint64_t units_count = 0;
	for( const auto unit : units )
	{
		units_count += unit * hundred_count * 9 + (100 * unit);
	}
	letter_count += units_count;
	
	timer::stop();
	return { "17.Number Letter Counts", get_result_string( letter_count ), timer::get_elapsed_seconds() };
	
}