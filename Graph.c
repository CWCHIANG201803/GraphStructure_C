#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#include "Graph.h"

// this is an implementation of graph written with C to imitate the C++ class 
// In this project, custom linked-list and queue are established to implement the graph structure
// this implementation takes the materials in the following website as a reference
// http://alrightchiu.github.io/SecondRound/graph-introjian-jie.html


typedef struct graph{
    // this is a base array of linked list
    // this is an alternative way to express graph.
    LinkedList** AdjList;

    // color is used to record the states of a node. 
    // there are three colors: white, grey, and black
    // white indicates the initial state
    // grey means the node has been discovered
    // black means search ends
    int* color;

    // vertexNumber is 
    int vertexNumber;

    // predecessor records the precedent vertex of the current vertex
    int *predecessor;

    // discover is used to denote the time when the vertex is discovered.
    int *discover;

    // finish denotes when the search ends, following the black color.
    int *finish;

    int *distance;
}Graph;

// constructor => initalize the date
Graph* new_Graph(int _vertexNumber){

    // allocate memory to the structure
    Graph* self = (Graph*)malloc(sizeof(Graph));
    
    // number of vertex in the graph
    self->vertexNumber = _vertexNumber;
    
    // initialize the array of linked list
    self->AdjList = (LinkedList**)malloc(self->vertexNumber*sizeof(LinkedList*));
    // initialize each linked list
    for(int i=0; i<self->vertexNumber;++i)
        self->AdjList[i] = new_List();

    // "self" here is paramount to "this" pointer in C++
    return self;
}

// this member functions aims to build graph structure
void AddEdgeList(Graph* self, int from, int to){
    InsertFromBack(self->AdjList[from],to);
}

// the recursion kernel of DFS
void DFSVisit(Graph* self, int _vertex,int *time){
    // mark the discovered vertex grey
    self->color[_vertex]=1;
    // discover time +1
    self->discover[_vertex] = ++(*time);
    // make linear search for the linked list and take the next vertex
    for(Node* it = GetFirstPtr(self->AdjList[_vertex]);it!=NULL;it = it->link){
        // when the next vertex has not been discovered
        // use this node as the traverse base.
        if(self->color[it->data]==0){
            // mark the predecessor
            self->predecessor[it->data] = _vertex;
            DFSVisit(self,it->data,time);
        }
    }
    // In conclusion, this loop is similar to traverse in linked list.
    // but this process contains tail recursion, so it can jump to another vertex
    // based on the connection rule(that is, the defined relation between vertices)

    // search ends, mark black
    self->color[_vertex] = 2;
    self->finish[_vertex]=++(*time);
}
// interface of method DFS
void DFS(Graph* self, int _StartVertex){
    // we allocate space for the variables here rather than in constructor
    // because we do only need them to record some properties of vertices
    // while doing DFS

    // 0 is white
    // 1 is grey
    // 2 is black
    self->color = (int*)malloc(self->vertexNumber*sizeof(int));
    self->discover = (int*)malloc(self->vertexNumber*sizeof(int));
    
    self->finish = (int*)malloc(self->vertexNumber*sizeof(int));
    self->predecessor = (int*)malloc(self->vertexNumber*sizeof(int));    

    int time = 0;
    int n;
    // initialization
    for(n=0;n<self->vertexNumber;n++){
        self->color[n] = 0;
        self->discover[n] = 0;
        self->finish[n] = 0;
        self->predecessor[n] = -1;
    }
    int i = _StartVertex;

    int j;
    // this loop can detect connected components in the graph
    for(j=0; j<self->vertexNumber;j++)
    {
        if(self->color[i] == 0){
            DFSVisit(self,i,&time);
        }
        i = j;
    }
}

// BFS => Breadth-First Search
void BFS(Graph* self, int _StartVertex){

    self->color = (int*)malloc(self->vertexNumber*sizeof(int));
    self->predecessor = (int*)malloc(self->vertexNumber*sizeof(int));
    self->distance = (int*)malloc(self->vertexNumber*sizeof(int));    
    int i;
    for(i=0;i<self->vertexNumber;i++){
        self->color[i] = 0;
        self->predecessor[i] = -1;
        self->distance[i] = self->vertexNumber+1;
    }
    printf("initialization ends\n");
    Queue* queue = new_Queue();
    i = _StartVertex;
    int j;
    for(j=0; j<self->vertexNumber;j++){
        if( self->color[i] == 0){
            // mark grey
            self->color[i] = 1;
            self->distance[i] = 0;
            self->predecessor[i] = -1;
            Enqueue(queue,i);
            while(!IsEmpty(queue)){
                // get the element for current index from queue
                int u = front(queue);
                int itrCount=0;
                for(Node* it = GetFirstPtr(self->AdjList[u]);it!=NULL;it = it->link){
                    if(self->color[it->data]==0){
                        // mark grey
                        self->color[it->data] = 1;
                        self->distance[it->data] = self->distance[u]+1;
                        self->predecessor[it->data] = u;
                        // to record the index of the next vertex
                        Enqueue(queue,it->data);
                    }
                    itrCount++;
                }
                Dequeue(queue);
                // mark blck
                self->color[u] = 2;
            }
        }
        i = j;
    }
    printf("search ends\n");
}
#endif