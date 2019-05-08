#ifndef GRAPH_H
#define GRAPH_H
typedef struct graph Graph;
// constructor => initalize the date
Graph* new_Graph(int);
// this member functions aims to build graph structure
void AddEdgeList(Graph*, int, int);
// the recursion kernel of DFS
void DFSVisit(Graph*, int,int*);
// interface of method DFS
void DFS(Graph*, int);
// BFS => Breadth-First Search
void BFS(Graph*, int);
#endif