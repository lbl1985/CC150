//Given an integer, write a function to determine if it is a power of three.
//
//Follow up :
//Could you do it without using any loop / recursion ?
// Author Binlong Li     01/08/2016


#include "..\inc\utils.h"

bool isPowerOfThree(int n) {
	if (n <= 0) {
		return false;
	}
	if (1 == n) {
		return true;
	}

	while (1 != n) {
		if (n % 3 != 0) {
			return false;
		}
		n /= 3;
	}
	return true;
}

int Q326_PowerOfThree() {
	int n = 27;
	string str = isPowerOfThree(n) ? " is " : " is not ";
	cout << n << str.c_str() << " power of 3" << endl;
	return 0;
}