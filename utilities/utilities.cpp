#include "utilities.h"


//************************************
// Method:    is_prime
// Access:    public 
// Returns:   bool
// Parameter: unsigned long long value
// Evaluate is the passed in parameter is a prime number
// returns true if prime.
//************************************
bool PE::is_prime( unsigned long long value )
{
	if ( value <= 1 ) return false;
	if ( value <= 3 ) return true;

	if ( !(value % 2) || !(value % 3) ) return false;

	for ( unsigned long long i = 5; i * i <= value; i += 6 )
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
uint64_t PE::factorial( uint64_t n )
{
	if( n == 1 )
	{
		return 1;
	}
	return n * factorial( n - 1 );
}