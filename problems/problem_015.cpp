/**
* Problem 15
* Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly
* 6 routes to the bottom right corner.
* 
* How many such routes are there for a 20x20 grid?
* 
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#include <vector>

Result PE::problem_015()
{
	timer::start();
	
	//This problem is an accumulation problem. Along each edge of the grid we can accumulate how many paths there are to a point.
	//For a 2x2 grid there are three points across and three points down counting each point as an intersection of lines not as the center of the grid
	//  _ _
	// |_|_|
	// |_|_|
	//
	// Leading edge column 0 there is one path to each position. Path to [0,0] = 1, path to [1,0] = 1, path to [2,0] = 1 same for rows
	// Leading edge row 0 there is one path to each position. Path to [0,0] = 1, path to [0,1] = 1, path to [0,2] = 1.
	// This produces the following grid:
	// 
	// 1 1 1
	// 1 x x
	// 1 x x
	//
	// x values can be found by accumulating the values to the immediate left and immediate up of the x location for example [1,1] has a value of 2 ([0,1] + [1,0] = 2)
	// This accumulation works for a grid of any size.
	constexpr int64_t gridsize = 20;
	constexpr int64_t edge_count = gridsize + 1;
	//create a vector to hold the grid and set all values to 0
	std::vector<uint64_t> grid( edge_count * edge_count, 0 );
	//set initial row of grid to value 1.
	for ( int64_t i = 0; i < edge_count; i++ )
	{
		//set row value
		grid[i] = 1;
		//set column value
		grid[i * edge_count] = 1;
	}

	//grid has been initialized populate grid from starting values
	for ( int64_t i = edge_count + 1; i < edge_count * edge_count; ++i )
	{
		int64_t x = i % edge_count;
		if ( x > 0 )
		{
			grid[i] = grid[i - 1] + grid[i - edge_count];
		}
	}
	timer::stop();

	return { "15.Lattice Paths", get_result_string( grid[edge_count * edge_count - 1]), timer::get_elapsed_seconds() };

}