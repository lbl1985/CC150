// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
// Example 1:

// Input: k = 3, n = 7

// Output: 

// [[1,2,4]]




// Example 2:

// Input: k = 3, n = 9

// Output: 

// [[1,2,6], [1,3,5], [2,3,4]]

// vector<vector<int>> combinationSum3(int k, int n) {    
// }
// Finish: 06/07/2016



#include "utils.h"

vector<vector<int>> csHelper(int k, int n, int start)
{
    vector<vector<int>> res;
    vector<int> t;

    int sum_low = 0;
    int sum_high = 0;
    for(int i = 0; i < k; i ++){
        sum_low += start + i;
        sum_high += 9 - i;
    }
    if(sum_low > n || sum_high < n){
        return res;
    }
    if (k == 1) {
        t.push_back(n);
        res.push_back(t);
        return res;
    }

    for(int i = start; i <= 9; i++){
        vector<vector<int>> tres = csHelper(k - 1, n - i, i + 1);
        if(tres.size() > 0) {
            for(int j = 0; j < tres.size(); j++) {
                tres[j].insert(tres[j].begin(), i);
                res.push_back(tres[j]);
            }
        }
    }
    return res;
}
vector<vector<int>> combinationSum3(int k, int n) {
    return csHelper(k, n, 1);
}

void printVV(const vector<vector<int>>& v)
{
    printf("[");
    for(int i = 0; i < v.size(); i++){
        printf("[");
        for(int j = 0; j < v[i].size(); j++){
            printf("%d,", v[i][j]);
        }
        printf("]");
    }
    printf("]");
}

int Q216_CombinationSumIII()
{
    // printf("test1: 3, 7\n");
    // vector<vector<int>> res1 = combinationSum3(3, 7);
    // printVV(res1); cout << endl;
	
    printf("test2: 3, 15\n");
    printf("expect: [[1,5,9],[1,6,8],[2,4,9],[2,5,8],[2,6,7],[3,4,8],[3,5,7],[4,5,6]]\n");
    vector<vector<int>> res2 = combinationSum3(3, 15);
    printVV(res2); cout << endl;

    return 0;
}