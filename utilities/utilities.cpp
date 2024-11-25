#include "utilities.h"

#include <chrono>


//************************************
// Method:    is_prime
// Access:    public 
// Returns:   bool
// Parameter: unsigned long long value
// Evaluate is the passed in parameter is a prime number
// returns true if prime.
//************************************
bool PE::is_prime( int64_t value )
{
	if ( value <= 1 ) return false;
	if ( value <= 3 ) return true;

	if ( !(value % 2) || !(value % 3) ) return false;

	for ( int64_t i = 5; i * i <= value; i += 6 )
	{
		if ( !(value % i) || !(value % (i + 2)) ) return false;
	}
	return true;
}


//************************************
// Method:    factorial
// Access:    public 
// Returns:   int32_t
// Qualifier:
// Parameter: int32_t n
// Recursive implementation of factorial
//************************************
uint64_t PE::get_factorial( uint64_t n )
{
	if( n == 1 )
	{
		return 1;
	}
	return n * get_factorial( n - 1 );
}

//************************************
// Method:    factors
// Access:    public 
// Returns:   std::vector<uint32_t>
// Qualifier:
// Parameter: uint32_t n
// Returns a vector containing the factors of the number passed in
//************************************
std::vector<uint32_t> PE::get_factors( const uint32_t n )
{
	std::vector<uint32_t> factors(1, 1u);
	//Only need to test up to the square root of a number to reduce range of tests
	const uint64_t sqrt_n = static_cast<uint32_t>(sqrt( n ));
	const auto max_factor = sqrt_n;
	uint32_t factor = 2;
	while ( factor <= max_factor )
	{
		if ( n % factor == 0 )
		{
			factors.push_back( factor );
			//get the larger factor
			const uint32_t larger_factor = n / factor;
			if ( factor != larger_factor ) //don't add the larger factor if this is a square of the number
			{				
				factors.push_back( larger_factor );
			}
		}
		factor++;
	}
	return factors;
}
