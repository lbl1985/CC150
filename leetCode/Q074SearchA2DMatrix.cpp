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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if(target < matrix[0][0]) return false;
        if(target > matrix[m - 1][n - 1]) return false;
        int row = m / 2;
        // per row binary search
        while(row > 0 && row < m) {
            if(target == matrix[row][n - 1] || target == matrix[row - 1][n - 1]) return true;
            if(target < matrix[row][n - 1] && target > matrix[row - 1][n - 1] ) break;
            if(target < matrix[row][n - 1]) {
                row = row / 2;
            } else {
                row = (row + 1 + m - 1) / 2;
            }
        }
        int start = 0, end = n - 1;
        int col = (start + end) / 2;
        // per col binary search
        if (target == matrix[row][0]) return true;
        while(col >= 0 && col < n && start <= end) {
            if(target == matrix[row][col]) return true;
            if(target < matrix[row][col]){
                end = col - 1;
                col = (start + end) /2;
            } else {
                start = col + 1;
                col = (start + end) / 2;
            }
        }
        return false;
    }
};