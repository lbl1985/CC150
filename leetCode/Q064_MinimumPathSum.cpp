// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSumHelper(int m, int n, const vector<vector<int>>& grid, vector<vector<int>>& rec)
    {
        if(m == m_rows - 1 && n == m_cols - 1){
            rec[m][n] = grid[m][n];
            return grid[m][n];
       }
       if(rec[m][n] == -1) {
           int cur = grid[m][n];
           rec[m][n] = cur + min(m < (m_rows - 1) ? minPathSumHelper(m+1, n, grid, rec) : INT_MAX, 
                             n < (m_cols - 1) ? minPathSumHelper(m, n+1, grid, rec) : INT_MAX);
       }
       return rec[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m_rows = (int)grid.size();
        m_cols = (int)grid[0].size();
        if(m_rows == 0 || m_cols == 0) return 0;
        if(m_rows == 1 && m_cols == 1) return grid[0][0];
        int s = max(m_rows, m_cols);
        vector<vector<int>> rec;
        for(int i = 0; i < s; i++){
            rec.push_back(vector<int>(s, -1));
        }
        return minPathSumHelper(0, 0, grid, rec);
    }
private:
    int m_rows;
    int m_cols;
    
};

int Q064_minPathSum()
{
    vector<vector<int>> test2;
    test2.push_back(vector<int>{1, 2});
    test2.push_back(vector<int>{1, 1});
    minPath mp;
    printf("minPathSum result: %d\n", mp.minPathSum(test2));

	printf("inside of Q064_minPathSum\n");
	return 0;
}