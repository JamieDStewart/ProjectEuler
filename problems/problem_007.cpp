/**
* Problem 7
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
* What is the 10 001st prime number?
*/
#include "problems.h"
#include "utilities.h"


void PE::problem_007()
{
	int count = 6;			//Taken from question
	unsigned long long prime = 13;	//Taken from question
	unsigned long long value = 14;
	while (count != 10001)
	{
		if (is_prime(value))
		{
			prime = value;
			++count;
		}
		++value;
	}
	std::cout << " 10, 001st Prime is: " << prime << std::endl;
}