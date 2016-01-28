// 4.2 Given a directed graph, design an algorithm to find out whether there is a route
// between two nodes
// Author: Binlong Li
// Date:   01/27/2016

#include <iostream>
#include <vector>
using namespace std;

enum State{
	Unvisited = 0,
	visiting,
	visited
};

struct Node{
	Node():data(0), s(Unvisited){}
	Node(int d):data(d), s(Unvisited){}

	int data;
	State s;
	vector<Node*> vNext;
};

// Create the following graph
// 0 -> 1 -> 2 -> 3
// |              ^
// | -> 4 -> 5 -> 6
//      |    | -> 7
//      |         ^
//      |---------|
// 
Node* createGraph(){
	Node* head = new Node(0);		
	head->vNext.push_back(new Node(1));	// 0 -> 1	
	head->vNext[0]->vNext.push_back(new Node(2)); // 1 -> 2
	head->vNext[0]->vNext[0]->vNext.push_back(new Node (3)); // 2 -> 3

	head->vNext.push_back(new Node(4)); // 0 -> 4
	head->vNext[1]->vNext.push_back(new Node(5)); // 4 -> 5
	head->vNext[1]->vNext.push_back(new Node(7)); // 4 -> 7

	head->vNext[1]->vNext[0]->vNext.push_back(new Node(6)); // 5 -> 6
	head->vNext[1]->vNext[0]->vNext.push_back(head->vNext[1]->vNext[1]); // 5 -> 7

	head->vNext[1]->vNext[0]->vNext[0]->vNext.push_back(head->vNext[0]->vNext[0]->vNext[0]); // 6-> 3
	return head;
}

int C4Q2(){
	Node* head = createGraph();
	cout << "inside C4Q2" << endl;
	return 0;
}