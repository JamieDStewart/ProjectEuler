/**
* Problem 9
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
* a^2 + b^2 = c^2
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*/

#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
	int product = 0;
	int sum = 1000;
	for (int a = 1; a < sum; ++a)
	{
		for (int b = a+1; b < sum; ++b)
		{
			int c = sum - a - b;
			if ((a * a + b * b) == (c * c))
			{
				product = a * b * c;
			}
		}
	}
	printf("The product of abc is: %i", product);
}