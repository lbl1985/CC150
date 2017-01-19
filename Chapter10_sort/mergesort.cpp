#include "../inc/utils.h"
#include <vector>

using namespace std;


void merge(vector<int>& data, int low, int middle, int high)
{
	vector<int> helper(data);
	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;
	while(helperLeft <= middle && helperRight <= high) {
		if(helper[helperLeft] <= helper[helperRight]) {
			data[current] = helper[helperLeft];
			helperLeft++;
		} else {
			data[current] = helper[helperRight];
			helperRight++;
		}
		current++;
	}

	int reminder = middle - helperLeft;
	for(int i = 0; i <= reminder; i++) {
		data[current++] = helper[helperLeft++];
	}
}

void mergesort(vector<int>& data, int low, int high)
{
	if(low < high) {
		int mid = (low + high) / 2;
		mergesort(data, low, mid);
		mergesort(data, mid + 1, high);
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
