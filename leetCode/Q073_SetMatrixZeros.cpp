// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 

// Follow up: 
// Did you use extra space?
//  A straight forward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//  Could you devise a constant space solution? 


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, int> removeRow;
        map<int, int> removeCol;
        int rows = matrix.size();
        if(rows == 0) return;
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0) {
                    removeRow[i] = 1;
                    removeCol[j] = 1;
                }
            }
        }
        // remove rows
        for(auto it = removeRow.begin(); it != removeRow.end(); it++){
            int r = it->first;
            for(int j = 0; j < cols; j++){
                matrix[r][j] = 0;
            }
        }
        // remove cols
        for(auto it = removeCol.begin(); it != removeCol.end(); it++){
            int c = it->first;
            for(int i = 0; i < rows; i++){
                matrix[i][c] = 0;
            }
        }
    }
};