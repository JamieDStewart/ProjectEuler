/**
* Problem 67
* By starting at the top to the triangle below and moving to adjacent numbers on the row below, the maximum total
* from top to bottom is 23.
*     3           3
*    7 4         7
*	2 4 6         4
*  8 5 9 3         9
*
*  That is 3 + 7 + 4 + 9 = 23
*  Find the maximum total from top to bottom of the triangle input from 0067_input.txt where triangle contains 100 rows!
*
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

Result PE::problem_067()
{
	timer::start();
	std::vector<uint32_t> input_triangle;

	//open the input file for reading
	std::ifstream file_input;
	file_input.open( "./input/0067_input.txt" );
	if ( file_input.is_open() )
	{
		//process each line of the file
		for ( std::string line; std::getline( file_input, line ); )
		{
			//get the value from the string stream as an integer
			std::stringstream ss( line );
			uint32_t val = 0;
			while ( ss >> val )
			{
				//add this value to the input triangle
				input_triangle.push_back( val );
			}			
		}
		//close the input file
		file_input.close();
	}

	//As need to visit each node in triangle simply sum each path as being created this will provide longest path value.
	std::vector<uint32_t> parent_row( input_triangle.begin(), input_triangle.begin() + 1 );

	//construct and output triangle from the beginning parent row
	std::vector<uint32_t> output_triangle( parent_row );


	uint32_t values_per_row = 2;
	uint32_t current_index = 1;
	//for each row in the input triangle
	while ( static_cast<size_t>(current_index + values_per_row) <= input_triangle.size() )
	{
		//fill current row
		std::vector<uint32_t> current_row( input_triangle.begin() + current_index, input_triangle.begin() + current_index + values_per_row );
		//set up an empty output row that contains the same number of values as the current row
		std::vector<uint32_t> output_row( values_per_row, 0 );
		//iterate over each parent in the parent row and work out the max value for the child
		uint32_t current_row_index = 0;
		for ( const auto val : parent_row )
		{
			//left child
			uint32_t output = current_row[current_row_index] + val;
			if ( output > output_row[current_row_index] )
			{
				output_row[current_row_index] = output;
			}
			//right child
			output = current_row[current_row_index + 1] + val;
			if ( output > output_row[current_row_index + 1] )
			{
				output_row[current_row_index + 1] = output;
			}
			current_row_index++;
		}

		current_index += values_per_row;
		values_per_row++;
		//set the current parent row to the just completed output_row
		parent_row = output_row;
		//append the parent row to the output triangle
		output_triangle.insert( output_triangle.end(), parent_row.begin(), parent_row.end() );

	}
	//get the largest element out of the output triangle's final row
	uint32_t max_value = *std::max_element( output_triangle.end() - values_per_row, output_triangle.end() );
	timer::stop();
	return { "67.Maximum Path Sum II", get_result_string( max_value), timer::get_elapsed_seconds() };
	
}