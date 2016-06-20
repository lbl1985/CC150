// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970." 

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article): 


// 1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 2.Any live cell with two or three live neighbors lives on to the next generation.
// 3.Any live cell with more than three live neighbors dies, as if by over-population..
// 4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.


// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 

// 1.Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// 2.In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        vector<vector<int>> nei;
        // neigh[1, 1] <=> board[0, 0]
        for(int i = 0; i < m + 2; i++) {
            nei.push_back(vector<int>(n + 2, 0));
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(board[i][j]){
                    for(int k = j; k <= j + 2; k++){
                        nei[i][k]++;
                    }
                    nei[i][j]++;
                    nei[i][j + 2]++;
                    for(int k = j; k <= j + 2; k++){
                        nei[i + 2][k]++;
                    }
                    
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(nei[i + 1][j + 1] < 2 || nei[i + 1][j + 1] > 3){
                    board[i][j] = 0;
                }
                if(nei[i + 1][j + 1] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
};