// Bubble Sort Test case
// Author: Binlong Li Date: 01/13/2016

#include "..\inc\utils.h"
#include <vector>

void bubbleSort(vector<int>& data)
{
	size_t sz = data.size();
	int tmp;
	for (int end = sz; end >1; end-- ) {		
		for (int i = 0; i < end - 1; i++) {
			if(data[i] > data[i+1]) {
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}
	}
}



int bubbleSortTest() {
	
	vector<int> arr{ 0, -2, 3, 9, 8, 67, 88, 92, -30, 50 };
	cout << "the array is: \n";
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	bubbleSort(arr);
	cout << "After the sorting the array is: \n";
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}