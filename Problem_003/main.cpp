/**
* Problem 3
* The prime factors of 13195 are 5, 7, 13 and 29.
* What is the largest prime factor of the number 600851475143 ?
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
	unsigned long long value = 600851475143;
	unsigned long long largestPrimeFactor = 0;
	if (isPrime(value)) largestPrimeFactor = value;
	if (largestPrimeFactor == 0)
	{
		unsigned long long maxValue = value;

		for (unsigned long long i = 2; i <= maxValue; ++i)
		{
			if (!(maxValue % i))
			{
				if (isPrime(i) && i > largestPrimeFactor)
				{
					maxValue = maxValue / i;
					largestPrimeFactor = i;
				}
			}
		}
	}
	printf("The largest prime factor of %llu is: %llu", value, largestPrimeFactor);
	return 0;

}