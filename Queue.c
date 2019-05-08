#include "Node.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	Node* FirstPtr;
	Node* LastPtr;
    int queueCapacity;
    int elementCount;
} Queue;

// constructor
Queue* new_Queue() {

	Queue* self = (Queue*)malloc(sizeof(Queue));
	self->FirstPtr = 0;
	self->LastPtr = 0;
    self->elementCount=0;
	return self;
}

int IsEmpty(Queue* self){
    return self->FirstPtr==NULL;
}

void Enqueue(Queue* self, int _value){
    Node* newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = _value;
    newPtr->link =NULL;

    if(self->elementCount==0){
        self->FirstPtr = newPtr;
        self->LastPtr = self->FirstPtr;
    }
    else{
        self->LastPtr->link = newPtr;
        self->LastPtr = newPtr;
    }
    self->elementCount++;
}

void Dequeue(Queue *self){
    Node* tmpPtr = self->FirstPtr;
    if(IsEmpty(self)){
        printf("The queue is empty!\n");
        return;
    }

    if(self->LastPtr!=self->FirstPtr)
    {
        self->FirstPtr = tmpPtr->link;
        tmpPtr->link = NULL;
        free(tmpPtr);
    }
    else
    {
        tmpPtr = self->LastPtr;
        self->FirstPtr = NULL;
        self->LastPtr = self->FirstPtr;
    }
    self->elementCount--;
}

void QueueDisplay(Queue* self){

    if(IsEmpty(self)){
        printf("the queue is empty\n");
        return;
    }

    printf("The data is :\n");

    for(Node *y = self->LastPtr; y!=NULL; y=y->link){
        printf("%p\t%d\n",y,y->data);
    }
}

int front(Queue* self){
    if(self->elementCount==0){
        return -1;
    }
    return self->FirstPtr->data;
}