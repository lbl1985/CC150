// Bubble Sort Test case
// Author: Binlong Li Date: 01/13/2016

#include "..\inc\utils.h"
#include <vector>

void bubbleSort(vector<int>& data)
{
	size_t n = data.size();
	int t;
	for(size_t i = 0; i < n; i++) {
		for(size_t j = i + 1; j < n; j++) {
			if(data[i] > data[j]) {
				t = data[i];
				data[i] = data[j];
				data[j] = t;
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