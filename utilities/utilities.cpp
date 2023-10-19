#include "utilities.h"

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