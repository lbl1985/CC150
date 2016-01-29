// 4.2 Given a directed graph, design an algorithm to find out whether there is a route
// between two nodes
// Author: Binlong Li
// Date:   01/27/2016

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

enum State{
	Unvisited = 0,
	visiting,
	visited
};

struct Node{
	Node():data(0), status(Unvisited){}
	Node(int d):data(d), status(Unvisited){}

	int data;
	State status;
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

// find all paths from head node
// save the results in vPath vector
void FindAllPaths(Node* head, vector<vector<Node*>> &vPaths){
	stack<Node*> s;
	s.push(head);
	head->status = visiting;
	while(!s.empty()){
	}	
}

bool search(Node* head, Node* start, Node* end){
	stack<Node*> s;
	s.push(start);
	start->status = visiting;
	while(!s.empty()){
		Node* u = s.top();
		s.pop();
		for(size_t i = 0; i < u->vNext.size(); i++){
			Node* v = u->vNext[i];
			if(v == end){
				return true;
			} else if(v->status != visited){
				v->status = visiting;
				s.push(v);
			}
		}
		u->status = visited;
	}
	return false;
}

void test(Node* head, Node* start, Node* end){
	cout << start->data << " and " << end->data << " is connect:" << (search(head, start, end) ? " ture" : " false") << endl;
}

int C4Q2(){
	Node* head = createGraph();	
	cout << "inside C4Q2" << endl;
	test(head, head->vNext[0], head->vNext[1]->vNext[0]);
	test(head, head->vNext[1], head->vNext[0]->vNext[0]->vNext[0]);
	return 0;
}