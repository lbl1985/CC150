// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
//  Given n = 3, 
// You should return the following matrix: [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n == 0) return res;
        if (n == 1) {
            vector<int> r1(1, 1);
            res.push_back(r1);
            return res;
        }
        vector<int> r(n, 0);
        for(int i = 0; i < n; i++){
            res.push_back(r);
        }
        int count = 1;
        for(int start = 0; start < n / 2; start++){
            // top row
            for(int j = start; j < n - start - 1; j++) {
                res[start][j] = count++;
            }
            // right column
            for(int j = start; j < n - start - 1; j++) {
                res[j][n - start - 1] = count++;
            }
            // bottom row;
            for(int j = n - start - 1; j > start; j--){
                res[n - start - 1][j] = count++;
            }
            // left column
            for(int j = n - start - 1; j > start; j--){
                res[j][start] = count++;
            }
        }
        if (n % 2 == 1) {
            res[n / 2][n/2] = n * n;
        }
        
        return res;
    }
};