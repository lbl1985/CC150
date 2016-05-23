// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK. 

// Note:

// 1.If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// 2.All airports are represented by three capital letters (IATA code).
// 3.You may assume all tickets form at least one valid itinerary.


// Example 1:
// tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//  Return ["JFK", "MUC", "LHR", "SFO", "SJC"].


// Example 2:
// tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//  Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
//  Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order. 

// vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
//     }

// Author: Binlong Li
// Date: 05/21/2016

#include "..\inc\utils.h"
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;

int getIndex(const vector<pair<string, string>>& vec, const vector<int>& validIndex)
{	
	int res = validIndex[0];
	int sz = (int)validIndex.size();
	if(sz == 1) {
		return res;
	}
	for(int i = 0; i < sz; i++) {
		if(vec[res].second.compare(vec[validIndex[i]].second) > 0) {
			res = validIndex[i];
		}
	}

	return res;
}

// recursive call based on arr info, 
bool getIter(unordered_map<string, vector<pair<string, string>>> dict, vector<string>& res) {
	while(!dict.empty()) {
		string cur = *(res.end() - 1);
		if(dict.count(cur)) {
			vector<pair<string, string>>& vec = dict[cur];
			int sz = (int)vec.size();
			if(sz == 1) {
				res.push_back(vec[0].second);
				dict.erase(cur);
			} else {
				vector<int> validIndex;
				for(int i = 0; i < sz; i++) {
					vector<string> tmpStr(res);
					tmpStr.push_back(vec[i].second);
					unordered_map<string, vector<pair<string, string>>> tmpDict(dict);
					vector<pair<string, string>>& tmpVec = tmpDict[cur];
					tmpVec.erase(tmpVec.begin() + i);
					if(getIter(tmpDict, tmpStr)) {
						validIndex.push_back(i);
					}
				}
				int index = getIndex(vec, validIndex);
				res.push_back(vec[index].second);
				vec.erase(vec.begin() + index);
			}
		} else {
			return false;
		}
	}
	return true;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, vector<pair<string, string>> >  dict;
    int sz = (int)tickets.size();
    unordered_map<string, int> dup;
    vector<string> res;
    res.push_back(string{"JFK"});
    for(int i = 0; i < sz; i++) {
    	auto it = dict.find(tickets[i].first);
    	if(dict.count(tickets[i].first) == 0) {
    		vector<pair<string, string>> tmp;
    		tmp.push_back(tickets[i]);
    		dict[tickets[i].first] = tmp;
    	} else {
    		dict[tickets[i].first].push_back(tickets[i]);
    	}
    }

    getIter(dict, res);

    return res;
}

void printVectorPair(const vector<pair<string, string>>& vec)
{
	cout << " [";
	int sz = (int)vec.size();
	for(int i = 0; i < sz; i++) {
		cout << "[" << vec[i].first << ", " << vec[i].second << "],";
	}

	cout << "] " << endl;
}

#define CONS_PAIR(IN1, IN2) pair<string, string>{(IN1), (IN2)}
int Q332_Reconstruct_Itinerary()
{
	printf("inside of Q332_Reconstruct_Itinerary\n");
	cout << "test1 " << endl;
	vector<pair<string, string>> test1{CONS_PAIR("MUC", "LHR"), CONS_PAIR("JFK", "MUC"), CONS_PAIR("SFO", "SJC"), CONS_PAIR("LHR", "SFO")};
	vector<string> res1 = findItinerary(test1);
	printVectorPair(test1); cout << endl;
	printf("expect: [JFK MUC LHR SFO SJC ]\nresult:");
	printVector<string>(res1); cout << endl;
	
	// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
	cout << endl << "test2 " << endl;
	vector<pair<string, string>> test2{CONS_PAIR("JFK","SFO"), CONS_PAIR("JFK","ATL"), CONS_PAIR("SFO","ATL"), CONS_PAIR("ATL","JFK"), CONS_PAIR("ATL","SFO")};
	vector<string> res2 = findItinerary(test2);
	printVectorPair(test2); cout << endl;
	printf("expect: [JFK ATL JFK SFO ATL SFO ]\nresult:");
	printVector<string>(res2); cout << endl;
	
	// [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
	cout << endl << "test3 " << endl;
	vector<pair<string, string>> test3{CONS_PAIR("JFK","KUL"), CONS_PAIR("JFK","NRT"), CONS_PAIR("NRT","JFK")};
	vector<string> res3 = findItinerary(test3);
	printVectorPair(test3); cout << endl;
	printf("expect: [JFK NRT JFK KUL ]\nresult:");
	printVector<string>(res3); cout << endl;
	return 0;
}