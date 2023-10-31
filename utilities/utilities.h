#pragma once
#include <cstdint>
#include <vector>

namespace PE
{
	extern bool is_prime( unsigned long long value );

	extern uint64_t get_factorial( uint64_t n );

	extern std::vector<uint32_t> get_factors( uint32_t n );

	extern void start_timer();

	extern double get_elapsed_time();

	extern void stop_timer();	

	
}