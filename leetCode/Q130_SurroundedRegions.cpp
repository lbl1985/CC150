// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// 
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// 
// For example,
// 
// X X X X
// X O O X
// X X O X
// X O X X
// 
// 
// 
// After running your function, the board should be :
// X X X X
// X X X X
// X X X X
// X O X X
// class Solution {
// public:
//     void solve(vector<vector<char>>& board)
//     {
// 
//     }
// };
// Another self example: 
// x x x x x x
// x o o o x o
// x o o o o x
// x x x o x o
// x o o x o x 
// x x o x o x
// After change should be: 
// x x x x x x
// x x x x x o
// x x x x x x
// x x x x x o
// x o o x o x
// x x o x o x
// Author: Binlong Li
// Date: 02/24/2016
