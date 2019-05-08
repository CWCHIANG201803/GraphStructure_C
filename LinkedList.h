#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
typedef struct linkedList LinkedList;
LinkedList* new_List();
void InsertAtFront(LinkedList*, int);
void InsertFromBack(LinkedList*, int);
void Display(LinkedList*);
void ReverseList(LinkedList*);
void RemoveData(LinkedList*);
Node* GetFirstPtr();
#endif