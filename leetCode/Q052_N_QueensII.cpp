// Follow up for N-Queens problem.
// 
// Now, instead outputting board configurations, return the total number of distinct solutions.
// Author: Binlong Li 
// Date: 03/02/2016
// Finish: 03/02/2016
// Solve this problem at time of solving 051_N_Queens, 
// Therefore no need to setup the real test scenario
//
// Groud Truth: 
// 1 1 0 
// 2 0 0 
// 3 0 0 
// 4 2 0 
// 5 10 0 
// 6 4 0 
// 7 40 3 
// 8 92 9 
// 9 352 35 
// 10 724 95 
// 11 2680 378 
// 12 14200 2198 
// 13 73712 11628 
// 14 365596 62427 
// 15 2279184 410701 



#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

struct QueenNode{
	QueenNode(int v):val(v){}
	int val;
	vector<QueenNode*> next;
};

class Solution {
public:

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

int totalNQueens(int n) 
{
    if(n == 1){
        return 1;
    }
	vector<vector<string>> res;
	vector<vector<int>> idx;
	unordered_set<int> fullSet;
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
	
	return (int)idx.size();
}
};
