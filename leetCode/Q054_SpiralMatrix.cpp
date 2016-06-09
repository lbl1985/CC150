#include "..\inc\utils.h"

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

int Q054_SpiralMatrix()
{
	vector<vector<int>> test1;
	test1.push_back(vector<int>{1, 2, 3});
	test1.push_back(vector<int>{4, 5, 6});
	test1.push_back(vector<int>{7, 8, 9});
	vector<int> res1 = spiralOrder(test1);
	printf("inside of Q054_SpiralMatrix\n");
	return 0;
}