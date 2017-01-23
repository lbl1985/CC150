#include "../inc/utils.h"
#include <vector>

using namespace std;


void merge(vector<int>& data, int low, int middle, int high)
{
	vector<int> helper(data);
	int helperleft = low;
	int helperright = middle + 1;
	int current = low;
	while(helperleft <= middle && helperright <= high) {
		if(helper[helperleft] <= helper[helperright]) {
			data[current++] = helper[helperleft++];
		} else {
			data[current++] = helper[helperright++];
		}
	}

	int reminder = middle - helperleft;
	for(int i = 0; i <= reminder; i++) {
		data[current++] = helper[helperleft++];
	}
}

void mergesort(vector<int>& data, int low, int high)
{
	if(low < high) {
		int mid = (low + high) / 2;
		mergesort(data, low, mid);
		mergesort(data, mid+1, high);
		merge(data, low, mid, high);
	}
}

int mergesortTest()
{
	vector<int> tcase1({3, 2, 1, 58, 0, -5, 33, 98, -3});
	printf("This is mergesort test case, the array is: \n");
	printVector<int>(tcase1);
	mergesort(tcase1, 0, (int)(tcase1.size() - 1));
	printf("\nafter mergesort, the array is: \n");
	printVector<int>(tcase1);
	return 0;
}
