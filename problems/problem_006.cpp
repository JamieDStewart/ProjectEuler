/**
* Problem 6
* The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385
* The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)^2 = 3025
* Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is: 3025 - 385 = 2640
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include "problems.h"

void PE::problem_006()
{
	/**
	* This problem at first sounds like an iterative loop may be required.
	* HOwever there is Faulhaber's formula to solve this problem:
	* https://en.wikipedia.org/wiki/Faulhaber%27s_formula
	*/
	constexpr int N = 100;
	constexpr int sumOfNDigits = (N * (N + 1)) / 2;
	constexpr int digitSumSquared = sumOfNDigits * sumOfNDigits;
	constexpr int sumOfNSquaredDigits = (N * (N + 1) * (2 * N + 1)) / 6;
	std::cout << "The difference is: " << digitSumSquared - sumOfNSquaredDigits << std::endl;

}