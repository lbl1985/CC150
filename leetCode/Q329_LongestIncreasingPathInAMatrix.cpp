// Given an integer matrix, find the length of the longest increasing path.
// 
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
// 
// Example 1: 
// nums = [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// 
// 
// 
// Return 4
//  The longest increasing path is [1, 2, 6, 9].
// 
// Example 2: 
// nums = [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// 
// 
// 
// Return 4
//  The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// 
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         
//     }
// };
// AUthor: Binlong Li
// Date:   01/23/2016

//#include "..\inc\utils.h"
#include <vector>
#include <stack>
using namespace std;
#define DEBUG 0
typedef unsigned int uint;

#if DEBUG
void print2DVec(const vector<vector<int>> &vec){
    for(size_t i = 0; i < vec.size(); i++){
        for(size_t j = 0; j < vec[0].size(); j++){
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}

void print2DVec(int** arr, const int height, const int width)
{
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
#endif

struct pos
{
    pos(uint xp, uint yp) :x(xp), y(yp) {}
    uint x;
    uint y;
};

struct element
{
    element(pos pp, int valp) :val(valp), p(pp) {}
    int val;
    pos p;
};




class Solution
{
public:
    // get neighbors need to check 
    vector<element> getQualifiedNeighbor(const size_t& x, const size_t& y, const vector<vector<int>> & matrix)
    {
        vector<element> neighbor;
        int curVal = matrix[x][y];
        int height = (int)matrix.size();
        int width = (int)matrix[0].size();
        // top	
        if (x > 0 && curVal < matrix[x - 1][y]) {
            pos tmp(x - 1, y);
            neighbor.push_back(element(tmp, matrix[x - 1][y]));
        }
        // bottom
        if (x < (uint)(height - 1) && curVal < matrix[x + 1][y]) {
            pos tmp(x + 1, y);
            neighbor.push_back(element(tmp, matrix[x + 1][y]));
        }
        // left
        if (y > 0 && curVal < matrix[x][y - 1]) {
            pos tmp(x, y - 1);
            neighbor.push_back(element(tmp, matrix[x][y - 1]));
        }
        // right
        if (y < (uint)(width - 1) && curVal < matrix[x][y + 1]) {
            pos tmp(x, y + 1);
            neighbor.push_back(element(tmp, matrix[x][y + 1]));
        }
        return neighbor;
    }

    int getNodeLength(const size_t& x, const size_t& y, const vector<vector<int>>& matrix, int** st)
    {
        vector<element> neighbor = getQualifiedNeighbor(x, y, matrix);
        if (neighbor.empty()) {
#if DEBUG
            printf("pos (%d, %d), len %d\n", x, y, 1);
#endif
            return 1;

        } else {
            size_t n = (size_t)neighbor.size();
            int tmplen = 0;

            for (size_t i = 0; i < n; i++) {
                int nx = neighbor[i].p.x;
                int ny = neighbor[i].p.y;
                int tmpNLen = st[nx][ny];
                if (tmpNLen) {
                    if (tmpNLen + 1> tmplen) {
                        tmplen = tmpNLen + 1;
                    }
                } else {
                    st[nx][ny] = getNodeLength(nx, ny, matrix, st);
                    if (st[nx][ny]) {
                        if (st[nx][ny] + 1 > tmplen) {
                            tmplen = st[nx][ny] + 1;
                        }
                    }
                }
            }
#if DEBUG
            printf("pos (%d, %d), len %d\n", x, y, tmplen);
#endif
            return tmplen;
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0)
            return 0;

        uint height = matrix.size();
        uint width = matrix[0].size();

        int longest = 0;

        // st recode the length for each node
        int ** st = new int *[height];
        for (uint i = 0; i < height; i++) {
            st[i] = new int[width];
            memset(st[i], 0, width * sizeof(int));
        }

        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                st[i][j] = getNodeLength(i, j, matrix, st);
                if (longest < st[i][j]) {
                    longest = st[i][j];
                }
            }
        }

#if DEBUG
        printf("longest of the matrix is %d\n", longest);
        print2DVec(st, height, width);
#endif

        for (uint i = 0; i < height; i++) {
            delete[] st[i];
            st[i] = nullptr;
        }
        delete[] st;
        st = nullptr;

        return longest;
    }
};

int Q329_LongestIncreasingPathInAMatrix()
{
	vector<vector<int> > matrix;
	vector<int> tmp01{3, 4, 5};
	vector<int> tmp02{3, 2, 6};
	vector<int> tmp03{2, 2, 1};
	matrix.push_back(tmp01);
	matrix.push_back(tmp02);
	matrix.push_back(tmp03);

#if DEBUG
	print2DVec(matrix);
#endif

    Solution obj;
	obj.longestIncreasingPath(matrix);


	return 0;
}