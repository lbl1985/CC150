#include "..\inc\utils.h"
#include <algorithm>

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    if(m == 0) return {};
    
    int n = (int)matrix[0].size();
    int target = m * n;
    vector<int> res;
    int count = 0;

    for(int start = 0; start <= m / 2; start++){
        // top row
        for(int j = start; j < n - start - 1; j++){
            res.push_back(matrix[start][j]);
            if(++count == target) return res;
        }
        // right column
        for(int j = start; j < m - start - 1; j++){
            res.push_back(matrix[j][n - 1 - start]);
            if(++count == target) return res;
        }
        // bottom row
        for(int j = n - start - 1; j > start; j--){
            res.push_back(matrix[m - 1 - start][j]);
            if(++count == target) return res;
        }
        // left column
        for(int j = m - start - 1; j > start; j--){
            res.push_back(matrix[j][start]);
            if(++count == target) return res;
        }
    }
	if (m == n && (m & 1) == 1) {
		res.push_back(matrix[m / 2][m / 2]);
	}
    return res;
}


class minPath {
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

int Q054_SpiralMatrix()
{
	vector<vector<int>> test1;
	test1.push_back(vector<int>{1, 2, 3});
	test1.push_back(vector<int>{4, 5, 6});
	test1.push_back(vector<int>{7, 8, 9});
	vector<int> res1 = spiralOrder(test1);

    vector<vector<int>> test2;
    test2.push_back(vector<int>{1, 2});
    test2.push_back(vector<int>{1, 1});
    minPath mp;
    printf("minPathSum result: %d\n", mp.minPathSum(test2));

	printf("inside of Q054_SpiralMatrix\n");
	return 0;
}