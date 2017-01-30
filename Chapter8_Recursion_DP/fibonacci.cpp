#include "..\inc\utils.h"

int fibonacciTopDown(unsigned int n, unsigned int* memo) {
	if(n == 0 || n == 1) {
		memo[n] = n;
		return n;
	}
	memo[n] = fibonacciTopDown(n - 1, memo) + fibonacciTopDown(n - 2, memo);
	return memo[n];

}

unsigned int fibonacciMemorization(unsigned int n)
{
	unsigned int* memo = new unsigned int[n];
	return fibonacciTopDown(n, memo);
}

unsigned int fibonacciBottomUpMemorization(unsigned int n)
{
	if(n == 0 || n == 1) {
		return n;
	}

	unsigned int* memo = new unsigned int[n];
	for(int i = 0; i < n; i++) {
		memo[i] = 0;
	}
	memo[0] = 0; memo[1] = 1;
	for(int i = 2; i <n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];

	}
	return memo[n - 1] + memo[n-2];
}

unsigned int fibonacciBottomUpEasy(unsigned int n)
{
	int a = 0, b = 1, t;
	for(int i = 2; i < n; i++) {
		t = a + b;
		a = b;
		b = t;
	}
	return a + b;
}

int fibonacciTest()
{
	printf("TopDown Memorization\n");
	printf("fib 2:  %d, %d, %d\n", fibonacciMemorization(2), fibonacciBottomUpMemorization(2), fibonacciBottomUpEasy(2));
	printf("fib 3:  %d, %d, %d\n", fibonacciMemorization(3), fibonacciBottomUpMemorization(3), fibonacciBottomUpEasy(3));
	printf("fib 6:  %d, %d, %d\n", fibonacciMemorization(6), fibonacciBottomUpMemorization(6), fibonacciBottomUpEasy(6));
	printf("fib 12: %d, %d, %d\n", fibonacciMemorization(12), fibonacciBottomUpMemorization(12), fibonacciBottomUpEasy(12));
	printf("fib 15: %d, %d, %d\n", fibonacciMemorization(15), fibonacciBottomUpMemorization(15), fibonacciBottomUpEasy(15));
	// printf("Print inside of Fibonacci Test\n");  
	return 0;
}