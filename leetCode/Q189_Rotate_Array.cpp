// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 

// Note:
//  Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 

// void rotate(vector<int>& nums, int k) {
// }

// Author: Binlong Li
// Date: 05/23/2016

#include "..\inc\utils.h"

void rotate(vector<int>& nums, int k) {
	int n = (int)nums.size();
	vector<int> pos;
	vector<int> bk(nums);
	for(int i = 0; i < n; i++) {
		nums[(i + k) % n] = bk[i];
	}
}


int Q189_Rotate_Array()
{
	printf("inside of Q189_Rotate_Array\n");
	vector<int> test1{1, 2, 3, 4, 5, 6, 7};
	printf("test1, k = 3\n");
	printVector(test1); cout << endl;
	rotate(test1, 3);
	printf("expect: [5 6 7 1 2 3 4]\n");
	printf("result:"); printVector(test1);
	return 0;
}