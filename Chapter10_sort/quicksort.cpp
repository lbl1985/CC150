// Test file for quicksort
// Author: Binlong Li  Date: 01/15/2016

#include "..\inc\utils.h"
#include <vector>

void swap(int& a, int&b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(vector<int> &arr, size_t low, size_t high){
	int p = arr[high];
	size_t smallIndex = low;
	int tmp = 0;
	for(size_t i = low; i < high; i++){
		if(arr[i] <= p){
			swap(arr[i], arr[smallIndex]);			
			smallIndex++;
		}		
	}

	swap(arr[smallIndex], arr[high]);	
	return smallIndex;
}

void quicksort(vector<int> &arr, int low, int high){
	if(low < high){
		int middle = partition(arr, low, high);
		quicksort(arr, low, middle - 1);
		quicksort(arr, middle + 1, high);
	}
}


int quicksortTest(){
	cout << "This is quicksortTest" << endl;

	vector<int> arr{ 0, -2, 3, 9, 8, 67, 88, 92, -30, 50 };
	cout << "the array is: \n";
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	quicksort(arr, 0, arr.size()- 1);
	cout << "After quick sort the array is: \n";
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
