/**
* Problem 15
* Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly
* 6 routes to the bottom right corner.
* 
* How many such routes are there for a 20x20 grid?
* 
*/

#include "problems.h"
#include <vector>

void PE::problem_015()
{
	std::cout << "Problem 015" << std::endl;

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
	int32_t gridsize = 20;
	int32_t edge_count = gridsize + 1;
	//create a vector to hold the grid and set all values to 0
	std::vector<int64_t> grid( edge_count * edge_count, 0 );
	//set initial row of grid to value 1.
	for ( int32_t i = 0; i < edge_count; i++ )
	{
		//set row value
		grid[i] = 1;
		//set column value
		grid[i * edge_count] = 1;
	}

	//grid has been initialized populate grid from starting values
	for ( int32_t i = edge_count + 1; i < edge_count * edge_count; ++i )
	{
		int32_t x = i % edge_count;
		int32_t y = i * edge_count;
		if ( x > 0 )
		{
			grid[i] = grid[i - 1] + grid[i - edge_count];
		}
	}

	std::cout << "Value in lower grid position is:" << grid[edge_count * edge_count - 1] << std::endl;
		

}