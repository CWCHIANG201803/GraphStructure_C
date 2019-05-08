#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;
Queue* new_Queue();
int IsEmpty(Queue*);
void Enqueue(Queue*, int);
void Dequeue(Queue*);
void QueueDisplay(Queue*);
int front(Queue*);
#endif