// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:


// •Integers in each row are sorted in ascending from left to right.
// •Integers in each column are sorted in ascending from top to bottom.


// For example,

// Consider the following matrix: 
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]


// Given target = 5, return true.

// Given target = 20, return false.


class Solution {
public:
    bool searchMatrixHelper(const vector<vector<int>>& matrix)
    {
        if(m_lt.first == m_row || m_rb.first == m_row || m_lt.second == m_col || m_rb.second == m_col
            || m_lt.first == -1 || m_rb.first == -1 || m_lt.second == -1 || m_rb.second == -1) return false;
        
        if(m_target == matrix[m_lt.first][m_lt.second] || m_target == matrix[m_lt.first][m_rb.second]
            || m_target == matrix[m_rb.first][m_lt.second] || m_target == matrix[m_rb.first][m_rb.second]) return true;
            
        // compare to left top corner
        if(m_target < matrix[m_lt.first][m_lt.second]) return false;
        // compare to right bottom corner
        if(m_target > matrix[m_rb.first][m_rb.second]) return false;
        // compare to right top corner
        if(m_target < matrix[m_lt.first][m_rb.second]){
            m_rb.second--;
            return searchMatrixHelper(matrix);
        }
        if(m_target > matrix[m_lt.first][m_rb.second]) {
            m_lt.first++;
            return searchMatrixHelper(matrix);
        }
        // compare to left bottom corner
        if(m_target > matrix[m_rb.first][m_lt.second]){
            m_lt.second++;
            return searchMatrixHelper(matrix);
        }
        if(m_target < matrix[m_rb.first][m_lt.second]){
            m_rb.first--;
            return searchMatrixHelper(matrix);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m_row = (int)matrix.size();
        m_col = (int)matrix[0].size();
        m_lt = pair<int,int>{0, 0};
        m_rb = pair<int, int>{m_row - 1, m_col - 1};
        m_target = target;
        return searchMatrixHelper(matrix);
    }
private: 
    pair<int, int> m_lt;
    pair<int, int> m_rb;
    int m_target;
    int m_row;
    int m_col;
};