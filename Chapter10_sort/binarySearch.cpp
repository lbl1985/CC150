#include "..\inc\utils.h"

int binarySearch(const vector<int>& data, int x)
{
	int low = 0;
	int high = data.size() - 1;

	while(low <= high) {
		int mid = (low + high) / 2;
		if(x < data[mid]) {
			high = mid - 1;
		} else if (data[mid] < x) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int binarySearchRecursive(const vector<int>& data, const int x, int low, int high)
{
	if(low <= high) {
		int mid = (low + high) / 2;
		if(x < data[mid]) {
			return binarySearchRecursive(data, x, low, mid - 1);
		} else if (data[mid] < x) {
			return binarySearchRecursive(data, x, mid + 1, high);
		} else {
			return mid;
		}
	}
	return -1;
}


int binarySearchTest() 
{
	printf("\n");
	printf("binarySearch Test: array is: \n");
	vector<int> arr{ -30, -2, -2, 0, 3, 9, 8, 50, 67, 88, 92 };
	for(int i = 0; i < arr.size(); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("binarySearch for 50 : %d\n", binarySearch(arr, 50));
	printf("binarySearchRecursive for 50 : %d\n", binarySearchRecursive(arr, 50, 0, arr.size() - 1));
	printf("binarySearch for -2: %d\n", binarySearch(arr, -2));
	printf("binarySearchRecursive for -2: %d\n", binarySearchRecursive(arr, -2, 0, arr.size() - 1));
	printf("binarySearch for -31: %d\n", binarySearch(arr, -31));
	printf("binarySearchRecursive for -31: %d\n", binarySearchRecursive(arr, -31, 0, arr.size() - 1));


	return 0;
}