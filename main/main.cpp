
/**
* This is the main entry point for the Project Euler
*   main will call an extern function for each of the problems to run a particular problem change the number to that problems value
*
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "problems.h"
#include "result.h"

std::vector< Result( * )() > problems = {	PE::problem_001, PE::problem_002, PE::problem_003, PE::problem_004, PE::problem_005,
											PE::problem_006, PE::problem_007, PE::problem_008, PE::problem_009, PE::problem_010,
											PE::problem_011, PE::problem_012, PE::problem_013, PE::problem_014, PE::problem_015,
											PE::problem_016, PE::problem_017, PE::problem_018, PE::problem_019, PE::problem_020,
											PE::problem_021, PE::problem_022, PE::problem_023, PE::problem_024, PE::problem_025,
											PE::problem_026, PE::problem_027, PE::problem_028, PE::problem_029, PE::problem_030,
											PE::problem_067 };

void print_break_to_console()
{
	std::cout << "==========================================================================" << std::endl;
}

void print_x_spaces_console( int x )
{
	for ( int i = 0; i < x; ++i )
	{
		std::cout << ' ';
	}
}

void print_separator()
{
	std::cout << "||";
}

void print_heading_to_console()
{
	print_separator();
	print_x_spaces_console( 23 );
	std::cout << "Project Euler Problems";
	print_x_spaces_console( 26 );
	print_separator();
	std::cout << std::endl;
	print_break_to_console();
	print_separator();
	std::cout << "Problem";
	print_x_spaces_console( 32 );
	print_separator();
	std::cout << "Answer";
	print_x_spaces_console( 10 );
	print_separator();
	std::cout << "Time";
	print_x_spaces_console( 8 );
	print_separator();
	std::cout << std::endl;
	print_break_to_console();
}

int get_spaces( int64_t value )
{
	//get length of result digits using string stream ops
	std::string res_str;
	std::stringstream ss;
	ss << value;
	ss >> res_str;
	return static_cast<int>(res_str.size());
}

int get_spaces( double value )
{
	//get length of result digits using string stream ops
	std::string res_str;
	std::stringstream ss;
	ss << value;
	ss >> res_str;
	return static_cast<int>(res_str.size());
}

void print_result( const Result& result )
{
	print_separator();
	std::cout << result.name;
	print_x_spaces_console( 39 - static_cast<int>(result.name.size()) );
	print_separator();
	std::cout << result.answer;
	print_x_spaces_console( 16 - static_cast<int>(result.answer.size()) );
	print_separator();
	std::cout << result.execution_time;
	print_x_spaces_console( 12 - get_spaces( result.execution_time ) );
	print_separator();
}
int main(int argc, char* argv[])
{
	//Create a vector to store the results of each problem
	std::vector<Result> results = {};

	for ( const auto& question : problems )
	{
		results.push_back( question() );
	}
	//display results to console
	print_break_to_console();
	//print headings
	print_heading_to_console();
	double total_time_taken{};
	for ( const auto& result : results )
	{
		total_time_taken += result.execution_time;
		print_result( result );
		std::cout << std::endl;
	}
	print_break_to_console();

	std::cout << "Total Time: " << total_time_taken << std::endl;

	return 0;
}
