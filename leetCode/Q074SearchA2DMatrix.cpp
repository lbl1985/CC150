// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:


// •Integers in each row are sorted from left to right.
// •The first integer of each row is greater than the last integer of the previous row.


// For example,

// Consider the following matrix: 
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]


// Given target = 3, return true.

class Solution {
public:
    int binarySearchRow(const vector<vector<int>>& matrix, int target, int start, int end){
        if(start <= end){
            int mid = (start + end) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                return mid;
            }
            if (target < matrix[mid][0]){
                return binarySearchRow(matrix, target, start, mid - 1);
            } else {
                return binarySearchRow(matrix, target, mid + 1, end);
            }
        }
        return start == end ? start : end;
    }
    bool binarySearch(const vector<int>& matrix, int target, int start, int end){
        if(start <= end){
            int mid = (start + end) / 2;
            if(target == matrix[mid]) return true;
            if(target < matrix[mid]) return binarySearch(matrix, target, start, mid - 1);
            else return binarySearch(matrix, target, mid + 1, end);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        if(m == 0) return false;
        n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }
        int rowId = binarySearchRow(matrix, target, 0, m - 1);
        return binarySearch(matrix[rowId], target, 0, n - 1);
    }
private:
    int m;
    int n;
};