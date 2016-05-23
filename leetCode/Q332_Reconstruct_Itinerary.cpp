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

// recursive call based on arr info, 
bool getIter(unordered_map<string, vector<pair<string, string>>>& dict, vector<string>& res) {
	while(!dict.empty()) {
		string cur = *(res.end() - 1);
		if(dict.count(cur)) {
			vector<pair<string, string>>& vec = dict[cur];
			int sz = (int)vec.size();
			if(sz == 1) {
				res.push_back(vec[0].second);
				dict.erase(cur);
			} else {
				// because the vector of pari<string, string> is in order, 
				// once we find the first qualified result, it's already the 
				// shortest literate distance
				for(int i = 0; i < sz; i++) {
					vector<string> tmpStr(res);
					tmpStr.push_back(vec[i].second);
					unordered_map<string, vector<pair<string, string>>> tmpDict(dict);
					vector<pair<string, string>>& tmpVec = tmpDict[cur];
					tmpVec.erase(tmpVec.begin() + i);
					if(getIter(tmpDict, tmpStr)) {
						res = tmpStr;
						return true;
					}
				}
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
    	const pair<string, string>& curPair = tickets[i];
    	if(dict.count(curPair.first) == 0) {
    		vector<pair<string, string>> tmp;
    		tmp.push_back(tickets[i]);
    		dict[tickets[i].first] = tmp;
    	} else {
    		vector<pair<string, string>>& vec = dict[curPair.first];
    		int vecSz = (int)vec.size();
    		bool isInsert = false;
    		// keep the vector<pair<string, string>> in order
    		for(int j = 0; false == isInsert && j < vecSz; j++) {
    			if(curPair.second.compare(vec[j].second) < 0){
    				vec.insert(vec.begin() + j, tickets[i]);
    				isInsert = true;
    			} 
    		}
    		if(false == isInsert) {
    			vec.push_back(tickets[i]);
    		}
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

	//[["EZE","TIA"],["EZE","HBA"],["AXA","TIA"],["JFK","AXA"],["ANU","JFK"],["ADL","ANU"],["TIA","AUA"],["ANU","AUA"],["ADL","EZE"],["ADL","EZE"],["EZE","ADL"],["AXA","EZE"],["AUA","AXA"],["JFK","AXA"],["AXA","AUA"],["AUA","ADL"],["ANU","EZE"],["TIA","ADL"],["EZE","ANU"],["AUA","ANU"]]
	cout << endl  << "test4 " << endl;
	vector<pair<string, string>> test4{CONS_PAIR("EZE","TIA"),CONS_PAIR("EZE","HBA"),CONS_PAIR("AXA","TIA"),CONS_PAIR("JFK","AXA"),CONS_PAIR("ANU","JFK"),
										CONS_PAIR("ADL","ANU"),CONS_PAIR("TIA","AUA"),CONS_PAIR("ANU","AUA"),CONS_PAIR("ADL","EZE"),CONS_PAIR("ADL","EZE"),
										CONS_PAIR("EZE","ADL"),CONS_PAIR("AXA","EZE"),CONS_PAIR("AUA","AXA"),CONS_PAIR("JFK","AXA"),CONS_PAIR("AXA","AUA"),
										CONS_PAIR("AUA","ADL"),CONS_PAIR("ANU","EZE"),CONS_PAIR("TIA","ADL"),CONS_PAIR("EZE","ANU"),CONS_PAIR("AUA","ANU")};
	vector<string> res4 = findItinerary(test4);
	printVectorPair(test4); cout << endl;
	printf("expect: ");
	printf("result: ");
	printVector<string>(res4); cout << endl;

	//["CBR","JFK"],["TIA","EZE"],["AUA","TIA"],["JFK","EZE"],["BNE","CBR"],["JFK","CBR"],["CBR","AUA"],["EZE","HBA"],["AXA","ANU"],["BNE","EZE"],["AXA","EZE"],["AUA","ADL"],["OOL","JFK"],["BNE","AXA"],["OOL","EZE"],["EZE","ADL"],["TIA","BNE"],["EZE","TIA"],["JFK","AUA"],["AUA","EZE"],["ANU","ADL"],["TIA","BNE"],["EZE","OOL"],["ANU","BNE"],["EZE","ANU"],["ANU","AUA"],["BNE","ANU"],["CNS","JFK"],["TIA","ADL"],["ADL","AXA"],["JFK","OOL"],["AUA","ADL"],["ADL","TIA"],["ADL","ANU"],["ADL","JFK"],["BNE","EZE"],["ANU","BNE"],["JFK","BNE"],["EZE","AUA"],["EZE","AXA"],["AUA","TIA"],["ADL","CNS"],["AXA","AUA"]
	cout << endl << "test5 " << endl;
	vector<pair<string, string>> test5{CONS_PAIR("CBR","JFK"), CONS_PAIR("TIA","EZE"), CONS_PAIR("AUA","TIA"), CONS_PAIR("JFK","EZE"), CONS_PAIR("BNE","CBR"), 
										CONS_PAIR("JFK","CBR"), CONS_PAIR("CBR","AUA"), CONS_PAIR("EZE","HBA"), CONS_PAIR("AXA","ANU"), CONS_PAIR("BNE","EZE"), 
										CONS_PAIR("AXA","EZE"), CONS_PAIR("AUA","ADL"), CONS_PAIR("OOL","JFK"), CONS_PAIR("BNE","AXA"), CONS_PAIR("OOL","EZE"), 
										CONS_PAIR("EZE","ADL"), CONS_PAIR("TIA","BNE"), CONS_PAIR("EZE","TIA"), CONS_PAIR("JFK","AUA"), CONS_PAIR("AUA","EZE"), 
										CONS_PAIR("ANU","ADL"), CONS_PAIR("TIA","BNE"), CONS_PAIR("EZE","OOL"), CONS_PAIR("ANU","BNE"), CONS_PAIR("EZE","ANU"), 
										CONS_PAIR("ANU","AUA"), CONS_PAIR("BNE","ANU"), CONS_PAIR("CNS","JFK"), CONS_PAIR("TIA","ADL"), CONS_PAIR("ADL","AXA"), 
										CONS_PAIR("JFK","OOL"), CONS_PAIR("AUA","ADL"), CONS_PAIR("ADL","TIA"), CONS_PAIR("ADL","ANU"), CONS_PAIR("ADL","JFK"), 
										CONS_PAIR("BNE","EZE"), CONS_PAIR("ANU","BNE"), CONS_PAIR("JFK","BNE"), CONS_PAIR("EZE","AUA"), CONS_PAIR("EZE","AXA"), 
										CONS_PAIR("AUA","TIA"), CONS_PAIR("ADL","CNS"), CONS_PAIR("AXA","AUA")};
	vector<string> res5 = findItinerary(test5);
	printVectorPair(test5); cout << endl;
	printf("expect: ");
	printf("result: ");
	printVector<string>(res5); cout << endl;
	return 0;
}