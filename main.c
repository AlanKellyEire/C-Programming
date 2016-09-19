

#include <stdio.h>
#include "file1.h"
#include "file2.h"

int main() {
	//1. We execute the monkey_trouble function with different input arguments
	printf("----------------\n");
	monkey_trouble(1, 1);
	monkey_trouble(0, 0);
	monkey_trouble(1, 0);

	// 2. We execute the sum_double function with different input arguments
	printf("----------------\n");
	sum_double(1, 2);
	sum_double(3, 2);
	sum_double(2, 2);

	// 3. We execute the near_100_or_200 function with different input arguments
	printf("----------------\n");
	near_100_or_200(93);
	near_100_or_200(90);
	near_100_or_200(89);

	// 4. We flip the coin 4 times
	printf("----------------\n");
	flip_coin_n_times(4);

	// 5. We print the pattern with size 5
	printf("----------------\n");
	printing_pattern(5);

	// 6. We print any prime number from 1 to 20
	printf("----------------\n");
	prime_numbers(20);

	return 0;

}
