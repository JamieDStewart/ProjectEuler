/**
* Problem 9
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
* a^2 + b^2 = c^2
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*/

#include "problems.h"

void PE::problem_009()
{
	int product = 0;
	constexpr int sum = 1000;
	for (int a = 1; a < sum; ++a)
	{
		for (int b = a+1; b < sum; ++b)
		{
			const int c = sum - a - b;
			if ((a * a + b * b) == (c * c))
			{
				product = a * b * c;
			}
		}
	}
	std::cout << "The product of abc is: " << product << std::endl;
}