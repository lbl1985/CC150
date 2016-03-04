// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// 
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// 
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
// 
// For example,
//  There exist two distinct solutions to the 4-queens puzzle:
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
// 
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// 
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         
//     }
// };
// Author: Binlong Li
// Date: 02/29/2016
// Finish: 03/02/2016

#include "..\inc\utils.h"

#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

#define DEBUG 1

struct QueenNode{
	QueenNode(int v):val(v){}
	int val;
	vector<QueenNode*> next;
};

void removeItem(unordered_set<int>& neighbor, int val)
{
	unordered_set<int>::iterator fiter = neighbor.find(val);
	if(fiter != neighbor.end()){
		neighbor.erase(fiter);
	}
}

vector<QueenNode*> getPossibleChild(const unordered_set<int>& fullSet, const vector<int>& curSeq)
{
	int n = (int)fullSet.size();
	unordered_set<int> neighbor(fullSet);

	for(size_t i = 0; i < curSeq.size(); i++){
		removeItem(neighbor, curSeq[i]);
	}

	for(int iter = 1; iter <= (int)curSeq.size(); iter++ ){
		int x = curSeq.size() - iter;
		int y = curSeq[curSeq.size() - iter];

		if(x + iter < n && y + iter < n){
			removeItem(neighbor, y + iter);
		}

		if(x + iter < n && y - iter >= 0){
			removeItem(neighbor, y - iter);
		}	
	}
	
	
	vector<QueenNode*> neighborList;
	if(!neighbor.empty()){
		for(unordered_set<int>::iterator it = neighbor.begin(); it != neighbor.end(); it++){			
			neighborList.push_back(new QueenNode(*it));
		}
	}

	return neighborList;
}

void createNext(QueenNode* root, const unordered_set<int>& fullSet, const vector<int>& curSeq, vector<vector<int>>& idx){
	size_t targetLength = fullSet.size();
	root->next = getPossibleChild(fullSet, curSeq);
	for(size_t i = 0; i < root->next.size(); i++){
		vector<int> tmpSeq(curSeq);
		tmpSeq.push_back(root->next[i]->val);

		if((int)curSeq.size() == targetLength - 1){			
			idx.push_back(tmpSeq);
		} else{			
			createNext(root->next[i], fullSet, tmpSeq, idx);
		}
	}
}

vector<string> rowTemplate(int n)
{
	vector<string> tem;
	string str = "";
	for(int i = 0; i < n; i++){
		str += ".";
	}
	for(int i = 0; i < n; i++){
		string cur(str);
		cur[i] = 'Q';
		tem.push_back(cur);
	}
	return tem;
}

#if DEBUG
void printConfig(vector<string> vStr)
{
	int n = (int)vStr.size();
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++){
			printf("%c ", vStr[i][j]);
		}
		cout << endl;
	}
}
#endif

vector<vector<string>> solveNQueens(int n) 
{	
	vector<vector<string>> res;
	vector<vector<int>> idx;
	unordered_set<int> fullSet;

	vector<string> tem = rowTemplate(n);
#if DEBUG
	printConfig(tem);
#endif

	if(n == 1){
		string s = "Q";
		vector<string> tmpString; tmpString.push_back(s);
		res.push_back(tmpString);
		return res;
	}

	for(int i = 0; i < n; i++){
		fullSet.insert(i);
	}
	// for each number to be as root
	for(int i = 0; i < n; i++){		
		vector<int> curSeq;
		curSeq.push_back(i);
		QueenNode* root = new QueenNode(i);
		createNext(root, fullSet, curSeq, idx);
	}

	
	for(size_t i = 0; i < idx.size(); i++ ){
		vector<string> temRes;
		for(int j = 0; j < n; j++){
			temRes.push_back(tem[idx[i][j]]);
		}		
		res.push_back(temRes);
#if DEBUG
		printf("Solution %d\n", i);
		printConfig(temRes);
#endif
	}

	return res;	
}

int TotalNum(int n)
{
	vector<vector<string>> res;
	vector<vector<int>> idx;
	unordered_set<int> fullSet;

	vector<string> tem = rowTemplate(n);
	printConfig(tem);

	if(n == 1){
		string s = "Q";
		vector<string> tmpString; tmpString.push_back(s);
		res.push_back(tmpString);
		return 1;
	}

	for(int i = 0; i < n; i++){
		fullSet.insert(i);
	}
	// for each number to be as root
	for(int i = 0; i < n; i++){		
		vector<int> curSeq;
		curSeq.push_back(i);
		QueenNode* root = new QueenNode(i);
		createNext(root, fullSet, curSeq, idx);
	}
	printf("# of NQueen solution for %d is: %d\n", n, idx.size());
	for(size_t i = 0; i< idx.size(); i++){
		printf("%d:", i);
		for(size_t j = 0; j< idx[i].size(); j++){
			printf("%d ", idx[i][j]);
		}
		printf("\n");
	}
	return (int)res.size();
}

int Q051_N_Queens(){
	printf("inside of Q051_N_Queens();\n");
	solveNQueens(4);
	solveNQueens(5);
	solveNQueens(6);
	solveNQueens(7);
	// solveNQueens(8);
	return 0;
}