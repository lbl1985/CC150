// Test file for quicksort
// Author: Binlong Li  Date: 01/15/2016

#include "..\inc\utils.h"
#include <vector>
using namespace std;
void swap(int& a, int&b){
	int t = a; 
	a = b;
	b = t;
}

int partition(vector<int>& data, int left, int right)
{
	int pivot = data[(left + right) / 2];
	while(left <= right) {
		while(data[left] < pivot) left++;
		while(data[right] > pivot) right--;
		if(left <= right){
			swap(data[left], data[right]);
			left++;
			right--;		
		}
	}
	return left;
}

void quicksort(vector<int>& data, int left, int right)
{
	if(left > right){
		return;
	}
	int index = partition(data, left, right);
	if(left < index - 1) {
		quicksort(data, left, index - 1);
	}
	if(index < right){
		quicksort(data, index, right);
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
