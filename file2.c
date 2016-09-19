

#include "file2.h"

/*
------------------------------
 FUNCTION flip_n_times_a_coin
------------------------------
 Print the results of flipping a coin 'n' times.You will need to import the random module to simulate a coin flip.
*/

void flip_coin_n_times(int n) {
	// 1. Iterate n times the flip of the coin

		// 1.1.Simulate the flip with the randint function of the random module.
		// Import the stdlib external resource and use the function to rand get a 0 or a 1.

		// 1.2. If it is a 0 then print Tail. Otherwise print Head.
}

/*
---------------------------
 FUNCTION printing_pattern
---------------------------
 Print the following pattern by screen, where the maximum number of stars is passed as parameter :
 *
 * *
 * * *
 * * * *
 * * * * *
 * * * *
 * * *
 * *
 *
*/

void printing_pattern(int n) {
	// 1. We iterate for each of the increasing lines
		// 1.1.We iterate for all the stars to be printed
			// 1.1.1. On each iteration we print '* '

		// 1.2.We print the end of the line

	// 2. We iterate for each of the decreasing lines
		//2.1.We iterate for all the stars to be printed
			// 2.1.1. On each iteration we print '* '
		// 2.2. We print the end of the line
}

/*
---------------------------
 FUNCTION prime_numbers
---------------------------
 A natural number(i.e. 1, 2, 3, 4, 5, 6, etc.) is called a prime number(or a prime) if it has exactly two positive divisors, 1 and the number itself.
 Write a C function that takes an integer number ‘n’ to print any prime number between 1 and n.
*/

void prime_numbers(int n) {
	//1. We iterate for all the candidate numbers(the ones from 1 to n)
		// 1.1. We say our current candidate is a successful one.

		// 1.2. We iterate for all numbers[2..n - 1] and , if any of them turns to be a divisor, then we conclude the number is not prime
			// 1.2.1. If j is a divisor of candidate, then candidate is not successful, there is no need to continue iterating

			// 1.2.2.We increase the value of j
					
		// 1.3. If, after checking all numbers, the candidate is still successful, then we can conclude it is a prime number, so we can print it
}

