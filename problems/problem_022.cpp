/**
* Problem 21
* Using 0022_input.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
* Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
* For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
* So, COLIN would obtain a score of 938 * 53 = 49,714.
*
* What is the total of all the name scores in the file?
*/

#include <algorithm>

#include "problems.h"

#include <fstream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

struct name_score
{
	std::string name;
	int32_t score;
};

void PE::problem_022()
{
	std::cout << "Problem 022" << std::endl;

	//create a vector for storing the name_scores read in
	std::vector<name_score> name_scores = {};
	//open the input file for reading
	std::ifstream file_input;
	file_input.open( "./input/0022_input.txt" );
	if ( file_input.is_open() )
	{
		//process each line of the file
		for ( std::string line; std::getline( file_input, line ); )
		{
			std::string temp_string{};
			std::stringstream input_line( line );
			//names in input file are separated by comma
			while ( std::getline( input_line, temp_string, ',' ) )
			{
				//get sub string removing quotation marks
				std::string name( temp_string, temp_string.find_first_not_of( '\"'), temp_string.find_last_not_of('\"'));
				//make sure name is all uppercase for score calculation
				std::transform( name.begin(), name.end(), name.begin(), ::toupper );
				//work out name score
				int32_t score = 0;
				for( const auto letter : name )
				{
					score += letter - 'A' + 1;
				}
				name_scores.push_back( { name, score } );
			}
			
		}
		//close the input file
		file_input.close();
	}
	//all names read in and scores evaluated now sort array by name
	std::sort( name_scores.begin(), name_scores.end(), []( const name_score& a, const name_score& b ) { return a.name < b.name; } );

	uint64_t total_name_score = 0;
	for( int32_t index = 0; index < name_scores.size(); ++index)
	{
		total_name_score += name_scores[index].score * (index + 1);
	}

	std::cout << "Total name scores from file: " << total_name_score << std::endl;
}