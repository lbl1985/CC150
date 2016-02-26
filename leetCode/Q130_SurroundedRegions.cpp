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
// Finish Date: 02/26/2016

#include "..\inc\utils.h"
#include <vector>
#include <stack>
using namespace std;
struct pos{
	pos(int xi, int yi):x(xi), y(yi){}
	int x;
	int y;
};


vector<vector<char>> createExample1()
{	
	char x='X';
	char o='O';	
	int width = 6;
	int height = 6;
	char example[6][6]={{x, x, x, x, x, x}, {x, o, o, o, x, o}, {x, o, o, o, o, x}, 
					{x, x, x, o, x, o}, {x, o, o, x, o, x}, {x, x, o, x, o, x}};
	vector<vector<char>> board;
	for(int i = 0; i < height; i++){
		vector<char> tmp(example[i], example[i] + width);
		board.push_back(tmp);
	}
	return board;
}

vector<vector<char>> createExample2()
{	
	char x='X';
	char o='O';	
	int width = 3;
	int height = 3;
	char example[3][3]={{x, x, x}, {x, o,x}, {x, x, x}};
	vector<vector<char>> board;
	for(int i = 0; i < height; i++){
		vector<char> tmp(example[i], example[i] + width);
		board.push_back(tmp);
	}
	return board;
}

vector<vector<char>> createExample3()
{	
	char x='X';
	char o='O';	
	int width = 3;
	int height = 3;
	char example[3][3]={{o, o, o}, {o, o, o}, {o, o, o}};
	vector<vector<char>> board;
	for(int i = 0; i < height; i++){
		vector<char> tmp(example[i], example[i] + width);
		board.push_back(tmp);
	}
	return board;
}

//  ["OXOOOOOOO","OOOXOOOOX","OXOXOOOOX","OOOOXOOOO","XOOOOOOOX","XXOOXOXOX","OOOXOOOOO","OOOXOOOOO","OOOOOXXOO"]
vector<vector<char>> createExample4()
{	
	char x='X';
	char o='O';	
	int width = 9;
	int height = 9;
	char example[9][9]={{'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},{'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
						{'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},{'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O'},
						{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},{'X', 'X', 'O', 'O', 'X', 'O', 'X', 'O', 'X'},
						{'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},{'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
						{'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O'}};
	vector<vector<char>> board;
	for(int i = 0; i < height; i++){
		vector<char> tmp(example[i], example[i] + width);
		board.push_back(tmp);
	}
	return board;
}


void atomOper(int rowId, int colId, int **st, const vector<vector<char>>& board, stack<pos>& s, vector<pos>& list){
	if(!st[rowId][colId] && board[rowId][colId] == 'O'){
		st[rowId][colId] = 1;
		s.push(pos(rowId, colId));
		list.push_back(pos(rowId, colId));
	}
}

vector<pos> getConnectArea(int x, int y, const vector<vector<char>>& board, int **st)
{
	int height = (int)board.size();
	int width  = (int)board[0].size();

	vector<pos> list;

	stack<pos> s;	
	s.push(pos(x,y));
    
	while(!s.empty()){
		pos p = s.top();
		s.pop();
    	
    	if(!st[p.x][p.y]){
    		list.push_back(pos(p.x, p.y));	
    	}		

		// check all neighborhood
		int rowId, colId;
		// up		
		if(p.x > 0){
			rowId = p.x - 1;
			colId = p.y;
			atomOper(rowId, colId, st, board, s, list);
		}
		// down
		if(p.x < height - 1){
			rowId = p.x + 1;
			colId = p.y;
			atomOper(rowId, colId, st, board, s, list);
		}
		// left
		if(p.y > 0){
			rowId = p.x;
			colId = p.y - 1;
			atomOper(rowId, colId, st, board, s, list);
		}
		// right
		if(p.y < width -1){
			rowId = p.x;
			colId = p.y + 1;
			atomOper(rowId, colId, st, board, s, list);
		}
	}
	return list;
}

void flipO(const vector<pos>& list, vector<vector<char>>& board)
{
	for(size_t i = 0; i < list.size(); i++ ){
		board[list[i].x][list[i].y] = 'X';
	}
}

void solve(vector<vector<char>>& board)
{
	if(board.empty()){
		return;
	}
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
			if(board[x][y] == 'O' && !st[x][y]){
				vector<pos> list = getConnectArea(x, y, board, st);
				for(size_t i = 0;i < list.size(); i++){
					pos p = list[i];
					// if p is the the boarder point, cleanup the whole list and return empty
					if(p.x == 0 || p.y == 0 || p.x == height -1 || p.y == width -1){
						list.clear();
					
					}
				}
				if(!list.empty()){
					flipO(list, board);
				}
			}
		}
	}

	for(int i = 0; i < height; i++){
		delete [] st[i];
	}
}

int Q130_SurroundedRegions()
{	
	vector<vector<char>> board;
	
	// printf("\ntest case 1\n");
	// board = createExample1();
	// print2DMat<char>(board);
	// printf("\nAfter Change.\n");
	// solve(board);
	// print2DMat<char>(board);

	// printf("\ntest case 2\n");
	// board = createExample2();
	// print2DMat<char>(board);
	// printf("\nAfter Change.\n");
	// solve(board);
	// print2DMat<char>(board);

	// printf("\ntest case 3\n");
	// board = createExample3();
	// print2DMat<char>(board);
	// printf("\nAfter Change.\n");
	// solve(board);
	// print2DMat<char>(board);

	printf("\ntest case 4\n");
	board = createExample4();
	print2DMat<char>(board);
	printf("\nAfter Change.\n");
	solve(board);
	print2DMat<char>(board);

	return 0;
}

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {

    }
};