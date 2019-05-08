
#include "LinkedList.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct linkedList {
	Node* FirstPtr;
	Node* LastPtr;
} LinkedList;

LinkedList* new_List() {
	LinkedList* self = (LinkedList*)malloc(sizeof(LinkedList));
	self->FirstPtr = NULL;
	self->LastPtr = NULL;
	return self;
}

void InsertAtFront(LinkedList* self, int _element) {
	Node* newPtr = (Node*)malloc(sizeof(Node));
	newPtr->data = _element;
	newPtr->link = NULL;
	if (self->FirstPtr == 0) {
		self->LastPtr = newPtr;
		self->FirstPtr = self->LastPtr;
	}
	else {
		newPtr->link = self->FirstPtr;
		self->FirstPtr = newPtr;
	}
}

void InsertFromBack(LinkedList* self, int _element) {
	Node* newPtr = (Node*)malloc(sizeof(Node));
	newPtr->data = _element;
	newPtr->link = NULL;

	if (self->FirstPtr == NULL) {
		self->LastPtr = newPtr;
		self->FirstPtr = self->LastPtr;
	}
	else {
		self->LastPtr->link = newPtr;
		self->LastPtr = newPtr;
	}
}
void Display(LinkedList* self) {
	if (self->FirstPtr == NULL) {
		printf("The list is empty!\n");
		return;
	}
	Node* y = self->FirstPtr;
	while (y != NULL) {
		printf("%d ", y->data);
		y = y->link;
	}
	printf("\n");
}

void ReverseList(LinkedList* self)
{
	Node* previousPtr = NULL;
	Node* currentPtr = self->FirstPtr;
	Node* precedePtr = self->FirstPtr->link;


	while (precedePtr != NULL)
	{
		currentPtr->link = previousPtr;
		previousPtr = currentPtr;
		currentPtr = precedePtr;
		precedePtr = precedePtr->link;
	}
	currentPtr->link = previousPtr;
	self->FirstPtr = currentPtr;
}

void RemoveData(LinkedList* self)
{
	Node* ptr = self->FirstPtr;
	Node* p4d = NULL;

	while (ptr != NULL) {
		p4d = ptr->link;
		printf("ptr => %p,ptr->next %p\n", ptr, p4d);
		free(ptr);
		ptr = p4d;
	}
}

Node* GetFirstPtr(LinkedList* self){
	return self->FirstPtr;
}