// Implement pow(x, n)
 // double myPow(double x, int n) {
        
 //    }
// Author: Binlong Li
// Date: 05/16/2016
// Finish: 05/16/2016

#include "../inc/utils.h"
#include "math.h"

// bool is10Pow(double x){
// 	if(x > 1) {
// 		if ()
// 	}
// }

double myPow(double x, int n)
{
	double res = x;

	if(x == 0.0) {
		return 0;
	} else if (x == 1.0) {
	    return 1;
	} else if (x == -1) {
	    if (n % 2 == 0) {
	        return 1;
	    } else {
	        return -1;
	    }
	}

	if (n == 0) {
		return 1;
	} else if (n > 2147483646) {
		return 0;
	} else if (n < -2147483646) {
		return 0;
	} else if (n > 0) {
		for(int i = 1; i < n; i++) {
			res *= x;
		}
	} else if (n < 0) {
		res = myPow(x, -n);
		res = 1/ res;
	}
	return res;
}

int Q050_Pow_x_n()
{
	printf("inside of pow(x,n)\n");
	printf("10^0 = %f\n", myPow(10, 0));
	printf("3^-1 = %f\n", myPow(3, -1));
	printf(" 0.00001^ 2147483647 = %f\n", myPow(0.00001, 2147483647));
	printf("1 ^ 10 = %f\n", myPow(1, 10));
	printf("-1 ^ 4 = %f\n", myPow(-1, 4));
	printf("-1 ^ 5 = %f\n", myPow(-1, 5));
	return 0;
}