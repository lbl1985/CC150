#include "../inc/utils.h"
#include <vector>

using namespace std;


void merge(vector<int>& data, int low, int middle, int high)
{
	vector<int> helper(data);

	int middleDis = middle - low;
	int low_helper = low;
	int high_helper = middle + 1;
	int current = low;
	while(low_helper <= middle && high_helper <= high) {
		if(helper[low_helper] < helper[high_helper]) {
			data[current++] = helper[low_helper++];
		} else {
			data[current++] = helper[high_helper++];
		}
	}

	// copy the left part
	int residule = middle - low_helper;
	for(int i = 0; i <= residule; i++) {
		data[current++] = helper[low_helper++];
	}
	
}

void mergesort(vector<int>& data, int low, int high)
{
	if (low < high) {		
		int middle = (low + high) / 2;
		mergesort(data, low, middle);
		mergesort(data, middle + 1, high);
		merge(data, low, middle, high);
	}
}

int mergesortTest()
{
	printf("print inside of mergeTes\n");
	vector<int> tcase1({3, 2, 1, 58, 0, -5, 33, 98, -3});
	mergesort(tcase1, 0, (int)(tcase1.size() - 1));
	printVector<int>(tcase1);
	return 0;
}