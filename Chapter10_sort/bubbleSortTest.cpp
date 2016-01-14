// Bubble Sort Test case
// Author: Binlong Li Date: 01/13/2016

#include "..\inc\utils.h"
#include <vector>

void bubbleSort(vector<int> &arr) {
	int end = (int)arr.size();
	int temp = 0;
	for (int endIndex = end - 1; endIndex > 0; endIndex--) {
		for (int i = 0; i < endIndex; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
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