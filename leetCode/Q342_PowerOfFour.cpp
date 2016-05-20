// 342 Power of Four
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4. 

// Example:
//  Given num = 16, return true. Given num = 5, return false. 

// Follow up: Could you solve it without loops/recursion? 

// bool isPowerOfFour(int num) {
        
//     }
// Author: BInlong Li
// Date: 05/19/2016
// Finish: 05/19/2016

#include "..\inc\utils.h"

bool isPowerOfFour(int num)
{
	if(num == 0) {
		return false;
	} else if(num < 0) {
		return false;
	} else {
		if(1 == num || 1 << 2 == num || 1 << 4 == num || 1 << 6 == num || 1 << 8 == num 
			|| 1 << 10 == num || 1 << 12 == num || 1 << 14 == num || 1 << 16 == num
			|| 1 << 18 == num || 1 << 20 == num || 1 << 22 == num || 1 << 24 == num
			|| 1 << 26 == num || 1 << 28 == num || 1 << 30 == num){
			return true;
		}
	}
	return false;
}

int Q342_PowerOfFour()
{
	printf("inside of Power Of Four\n");
	return 0;
}