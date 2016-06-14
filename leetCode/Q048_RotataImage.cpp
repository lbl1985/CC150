// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
//  Could you do this in-place?

class Solution {
public:
    void swap(int& a, int& b){
        int temp;
        temp = a; a = b; b = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int temp;
        for(int i = 0; i < n / 2; i++){
            // top row to left column;
            for(int run = i; run < n - i - 1; run++){
                // top row to left column
                swap(matrix[i][run], matrix[n - run - 1][i]);
                // left column to bottom row
                swap(matrix[n - run - 1][i], matrix[n - i - 1][n - run - 1]);
                // bottom row to right column
                swap(matrix[n - i - 1][n - run - 1], matrix[run][n - i - 1]);
                // // right column to top row
                // swap(matrix[run][n - i - 1], matrix[i][run]);
            }
        }
    }
};