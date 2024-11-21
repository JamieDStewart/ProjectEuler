#pragma once
#include <cstdint>
#include <string>
#include <sstream>

struct Result
{
	const std::string	name;
	const std::string	answer;
	const double		execution_time;
};

template<class T>
std::string get_result_string( T result_value )
{
	std::stringstream ss;
	ss << result_value;
	return ss.str();
}
