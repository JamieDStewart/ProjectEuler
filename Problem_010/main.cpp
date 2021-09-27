/**
* Problem 10
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
* Find the sum of all the primes below two million.
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
	unsigned long long sum = 0;
	for (int i = 1; i < 0x1E8480; ++i)
	{
		if (isPrime(i))
		{
			sum += (unsigned long long)i;
		}
	}

	printf("Sum of primes below 2 million is: %llu", sum);
	return 0;
}