/**
* Problem 7
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
* What is the 10 001st prime number?
*/
#include <cstdio>

bool isPrime(unsigned long long value)
{
	if (value <= 1) return false;
	if (value <= 3) return true;

	if (!(value % 2) || !(value % 3)) return false;

	for (unsigned long long i = 5; i * i <= value; i += 6)
	{
		if (!(value % i) || !(value % (i + 2))) return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int count = 6;			//Taken from question
	unsigned long long prime = 13;	//Taken from question
	unsigned long long value = 14;
	while (count != 10001)
	{
		if (isPrime(value))
		{
			prime = value;
			++count;
		}
		++value;
	}
	printf(" 10, 001st Prime is: %llu", prime);
}