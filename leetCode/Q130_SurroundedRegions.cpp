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
#include "..\inc\utils.h"
#include <vector>
#include <stack>

using namespace std;

vector<vector<char>> createExample1()
{	
	char x='x';
	char o='o';	
	char example[6][6]={{x, x, x, x, x, x}, {x, o, o, o, x, o}, {x, o, o, o, o, x}, 
					{x, x, x, o, x, o}, {x, o, o, x, o, x}, {x, x, o, x, o, x}};
	vector<vector<char>> board;
	for(int i = 0; i < 6; i++){
		vector<char> tmp(example[i], example[i] + 6);
		board.push_back(tmp);
	}
	return board;
}

int Q130_SurroundedRegions()
{
	vector<vector<char>> board;
	board = createExample1();
	print2DMat<char>(board);
	return 0;
}

struct pos{
	pos(int xi, int yi):x(xi), y(yi){}
	int x;
	int y;
};

vector<pos> getConnectArea(int x, int y, const vector<vector<char>>& board, int **st)
{
	vector<pos> list;
	stack<pos> s;	
	s.push(pos(x,y));

	while(!s.empty()){
		pos p = s.top();
		s.pop();
		if(!st[p.x][p.y]){
			list.push_back(p);
		}
		// check all neighborhood

	}
	return list;
}

void solve(vector<vector<char>>& board)
{
	int height = (int)board.size();
	int width = (int)board[0].size();
	int **st = new int*[height];
	for(int i = 0; i < height; i++){
		st[i] = new int [width];
		memset(st[i], 0, width * sizeof(int));
	}

	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			// 
			if(board[x][y] == 'o' && !st[x][y]){
				vector<pos> list = getConnectArea(x, y, board, st);
			}
		}
	}

	for(int i = 0; i < height; i++){
		delete [] st[i];
	}
}

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {

    }
};