// Given an integer matrix, find the length of the longest increasing path.
// 
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
// 
// Example 1: 
// nums = [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// 
// 
// 
// Return 4
//  The longest increasing path is [1, 2, 6, 9].
// 
// Example 2: 
// nums = [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// 
// 
// 
// Return 4
//  The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// 
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         
//     }
// };
// AUthor: Binlong Li
// Date:   01/23/2016

#include "..\inc\utils.h"
#include <vector>
using namespace std;

void print2DVec(const vector<vector<int>> &vec){
	for(size_t i = 0; i < vec.size(); i++){
		for(size_t j = 0; j < vec[0].size(); j++){
			printf("%d ", vec[i][j]);
		}
		printf("\n");
	}
}

void print2DVec(int** arr, const int height, const int width)
{
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{	
	if(matrix.size() == 0)
		return 0;

	uint height = matrix.size();
	uint width = matrix[0].size();
	// vector< vector<int> > arr;

	int ** st = new int *[height];
	for(uint i = 0; i < height; i++){
		st[i] = new int[width];
		memset(st[i], 0, width * sizeof(int));
	}

	print2DVec(st, height, width);

	for(uint i = 0; i < height; i++){
		delete [] st[i];
		st[i] = nullptr;
	}
	delete [] st;
	st = nullptr;

	return 0;
}

int Q329_LongestIncreasingPathInAMatrix()
{
	vector<vector<int> > matrix;
	vector<int> tmp01{3, 4, 5};
	vector<int> tmp02{3, 2, 6};
	vector<int> tmp03{2, 2, 1};
	matrix.push_back(tmp01);
	matrix.push_back(tmp02);
	matrix.push_back(tmp03);


	print2DVec(matrix);

	longestIncreasingPath(matrix);


	return 0;
}