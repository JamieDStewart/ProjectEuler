/**
* Problem 18
* By starting at the top to the triangle below and moving to adjacent numbers on the row below, the maximum total
* from top to bottom is 23.
*     3           3
*    7 4         7
*	2 4 6         4
*  8 5 9 3         9
*
*  That is 3 + 7 + 4 + 9 = 23
*  Find the maximum total from top to bottom of the triangle below:
*
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#include <algorithm>
#include <vector>

Result PE::problem_018()
{
	timer::start();
	////std::vector<int32_t> input_triangle = { 3, 7, 4, 2, 4, 6, 8, 5, 3, 9 };
	std::vector<int32_t> input_triangle =
	{
		                        75,
	                          95, 64,
	                        17, 47, 82,
	                      18, 35, 87, 10,
	                    20,  4, 82, 47, 65,
	                  19,  1, 23, 75,  3, 34,
	                88,  2, 77, 73,  7, 63, 67,
	              99, 65,  4, 28,  6, 16, 70, 92,
	            41, 41, 26, 56, 83, 40, 80, 70, 33,
	          41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
	        53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
	      70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
	    91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
	  63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
	 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
	};	

	//Constructing a tree from the triangle and navigating through the tree going to max child does not produce the result.
	//This can be seen in the sample four level triangle if the 9 & 3 in the bottom row were swapped. Maximum path in example with swap
	//becomes 3 + 4 + 6 + 9 = 22, while if using max child path would be 3 + 7 + 4 + 5 = 19.

	//As need to visit each node in triangle simply sum each path as being created this will provide longest path value.
	std::vector<int32_t> parent_row( input_triangle.begin(), input_triangle.begin() + 1 );

	//construct and output triangle from the beginning parent row
	std::vector<int32_t> output_triangle( parent_row );
	

	int32_t values_per_row = 2;
	int32_t current_index = 1;
	//for each row in the input triangle
	while( static_cast<size_t>(current_index + values_per_row) <= input_triangle.size() )
	{
		//fill current row
		std::vector<int32_t> current_row( input_triangle.begin() + current_index, input_triangle.begin() + current_index + values_per_row );
		//set up an empty output row that contains the same number of values as the current row
		std::vector<int32_t> output_row( values_per_row, 0 );
		//iterate over each parent in the parent row and work out the max value for the child
		int32_t current_row_index = 0;
		for( const auto val : parent_row )
		{
			//left child
			int32_t output = current_row[current_row_index] + val;
			if ( output > output_row[current_row_index] )
			{
				output_row[current_row_index] = output;
			}
			//right child
			output = current_row[current_row_index+1] + val;
			if ( output > output_row[current_row_index+1] )
			{
				output_row[current_row_index+1] = output;
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
	int32_t max_value = *std::max_element( output_triangle.end() - values_per_row, output_triangle.end() );
	timer::stop();

	return { "18.Maximum Path Sum", get_result_string( max_value), timer::get_elapsed_seconds() };
	
}