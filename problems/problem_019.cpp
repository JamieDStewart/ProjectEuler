/**
* Problem 19
* You are given the following information, but you may prefer to do some research for yourself.
* 1 Jan 1900 was a Monday.
* Thirty days has September, April, June and November.
* All the rest have thirty-one, Saving February alone,Which has twenty-eight, rain or shine.
* And on leap years, twenty-nine.
*
* A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
*
* How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include "problems.h"
#include "result.h"
#include "timer.h"

#include <algorithm>
#include <vector>
#include <string>

Result PE::problem_019()
{
	timer::start();

	const std::vector<std::string> days_of_the_week = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	const std::vector<uint32_t> days_in_a_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	constexpr uint32_t starting_year = 1901;
	constexpr uint32_t starting_month = 0;
	uint32_t starting_date = 0;
	uint32_t day_of_the_week = 1; // 1st Jan 1901 was on a Tuesday.

	constexpr uint32_t years_to_cover = 100;

	uint32_t sunday_1st_count = 0;

	//loop for number of years to cover
	for( uint32_t i = 0; i < years_to_cover; ++i )
	{
		bool is_leap_year = (starting_year + i) % 4 == 0;
		if ( is_leap_year )
		{
			//test to make sure that if we're on a century that it's divisible by 400
			if ( (starting_year + i) % 100 == 0 )
			{
				is_leap_year = (starting_year + i) % 400 == 0;
			}
		}
		//iterate from the starting point by the number of days in that month
		for( uint32_t m = starting_month; m < days_in_a_month.size(); ++m )
		{
			const uint32_t days = days_in_a_month[m] - starting_date;
			if( starting_date != 0 )
			{
				starting_date = 0;
			}
			day_of_the_week = (day_of_the_week + days) % days_of_the_week.size();
			if( m == 1 && is_leap_year )
			{
				day_of_the_week = (day_of_the_week + 1) % days_of_the_week.size();
			}
			if( days_of_the_week[day_of_the_week] == "Sunday" )
			{
				sunday_1st_count++;
			}			
		}				
	}

	timer::stop();
	return { "19.Counting Sundays", get_result_string( sunday_1st_count ), timer::get_elapsed_seconds() };
	
}