#include "..\inc\utils.h"
#include "..\inc\GraphPrac.h"

//http://www.programming-techniques.com/2012/07/depth-first-search-in-c-algorithm-and.html

Graph::Graph(int size)
{
	if(size < 2) {
		n = 2;
	} else {
		n = size;
	}
	A = new int*[n];
	for(int i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

Graph::~Graph(){
	for(int i = 0; i < n; i++) {
		delete [] A[i];
	}
	delete [] A;
}

bool Graph::isConnected(int x, int y)
{
	return A[x-1][y-1] == 1;
}

void Graph::addEdge(int x, int y)
{
	// printf("Add Edge %d, %d\n", x, y);
	A[x-1][y-1] = A[y-1][x-1] = 1;
}

void printConnected(int x, int required)
{
	printf("%d is connected with %d\n", x, required);
}

void printNotConnected(int x, int required) 
{
	printf("\n%d is not connected with %d\n", x, required);
}

void Graph::DFS(int x, int required)
{	
	if(x == required) {
		printConnected(x, required);
		return;
	}
	bool found = false;
	bool* visited = new bool [n];
	for(int i = 0; i < n; i++) {
		visited[i] = false;
	}
	visited[x - 1] = true;
	stack<int> s;
	s.push(x);
	while(!s.empty()) {
		int top = s.top();
		printf("%d ", top);
		s.pop();
		if(top == required) {
			found = true;
			printConnected(x, required);
			break;
		}
		for(int i = 1; i <= n; i++) {
			if(isConnected(i, top) && visited[i - 1] == false) {
				visited[i - 1] = true;
				s.push(i);
			}
		}
	}
	if(!found) {
		printNotConnected(x, required);
	}
	delete [] visited;
}

void Graph::BFS(int x, int required)
{
	if(x == required) {
		printConnected(x, required);
		return;
	}
	bool found = false;
	bool* visited = new bool [n];
	for(int i = 0;  i < n; i++) {
		visited[i] = false;
	}
	visited[x - 1] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int front = q.front();
		printf("%d ", front);
		q.pop();
		if(front == required) {
			found = true;
			printConnected(x, required);
			break;
		}
		for(int i = 1; i <= n; i++) {
			if(isConnected(i, front) && visited[i - 1] == false) {
				visited[i - 1] = true;
				q.push(i);
			}
		}		
	}
	if(!found) {
		printNotConnected(x, required);
	}
	delete [] visited;
}

int GraphTest(){
	printf("This is Graph Test function\n");
	Graph g(8);
	g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 4);
	g.addEdge(2, 5); g.addEdge(2, 6); g.addEdge(4, 7);
	g.addEdge(4, 8);

	Graph g_2(8);
	g_2.addEdge(1, 2); g_2.addEdge(6, 3);
	g_2.addEdge(2, 5); g_2.addEdge(2, 6); g_2.addEdge(4, 7);
	g_2.addEdge(4, 8);
	
	printf("\nDFS\n");
	g.DFS(1, 4);
	g_2.DFS(2, 7);

	printf("\nBFS\n");
	g.BFS(1, 4);
	g_2.BFS(2, 7);

	return 0;
}