// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathHelper(int m, int n, vector<vector<int>>& rec){;
        if(m == 1 || n == 1){
            rec[m - 1][n - 1] = 1;
        }
        
        if(rec[m-1][n - 1] == 0){
            rec[m-1][n - 1] = uniquePathHelper(m - 1, n, rec) + uniquePathHelper(m, n - 1, rec);
        }
        
        return rec[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector< vector<int> > rec;
        int s = max(m, n);
        for(int i = 0; i < s; i++) {
            rec.push_back(vector<int>(s, 0));
        }
        

        return uniquePathHelper(m, n, rec);
    }
};