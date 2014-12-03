#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

/*
  Program implements a double linked list and can be used by
  including linked.h in file and compiling with linked_list.c
  gcc linked_list.c linked_test.c
*/

void addItem(Node* list, int data); void cleanList(Node*); void printList(Node*);
Node* createList(int); Node* getItemAfter(Node*); Node* removeNode(Node*);
//can remove these function things???

/* now test via linked_test.c via gcc linked_list.c linked_test.c -o...
int main(int argc, char* argv) {
	Node* nextOne;
	Node* test = createList(3);
	addItem(test, 4);
	addItem(test, 5);
	addItem(test, 7);
	addItem(test, 1);
	nextOne = getItemAfter(test);
	printf("TESTING - %i\n", test -> data);
	cleanList(nextOne -> next);
	
	printf("TESTING - end");
	return 0;
}
*/

//creates the first item in list
Node* createList(int data) {
	Node* startPtr = (Node*)malloc(sizeof(Node));
	if (startPtr == NULL) {
		printf("NULL PTR EXCEPTION");
	}
	
	startPtr -> data = data;
	startPtr -> next = NULL;
	startPtr -> previous = NULL;
	
	return startPtr;
}

//adds an item to the list and sets previous pointer to it
void addItem(Node* list, int data) {
	Node* oldEndPtr = list;
	Node* newPtr = malloc(sizeof(Node)); 
	if (newPtr == NULL) {
		printf("NULL PTR EXCEPTION");
	}
	
	//finds if only one node
	if (((oldEndPtr -> previous) == NULL) && ((oldEndPtr -> next) == NULL)) {
	} else {
		//loops to end node
		while (oldEndPtr -> next != NULL) {
			oldEndPtr = oldEndPtr -> next;
		}
	}
	
	//creates new node
	newPtr -> data = data;
	newPtr -> next = NULL;
	newPtr -> previous = oldEndPtr; 
	
	oldEndPtr -> next = newPtr;
}

//point to item after given
Node* getItemAfter(Node* currentItem) {
	if (currentItem -> next == NULL) {
		return NULL; 
	} else {
		return (currentItem -> next);
	}
}

//removes a given Node
Node* removeNode(Node* badNode) {
	Node* previousNode = badNode -> previous;
	Node* nextNode = badNode -> next; 
	
	//moves pointers to avoid badNode
	previousNode -> next = nextNode; 
	nextNode -> previous = previousNode;
	
	free(badNode);
	return(previousNode);
}

//print list of all nodes in structure
void printList(Node* list) {
	Node* curNode = list;
	int i = 0;
	
	//finds start node
	while (curNode -> previous != NULL) {
		curNode = curNode -> previous;
	}
	
	//loops over nodes and prints 
	while (curNode -> next != NULL) {
		printf("Node %i - value %i\n", i++, curNode -> data);
		curNode = curNode -> next;
	}
	
	//prints final node
	printf("Node %i - value %i\n", i, curNode -> data);
}

//attempts to free all allocated memory, run a valgrind on it
void cleanList(Node* start) {
	Node* curNode = start;
	
	//finds start node if not passed as arg
	while (curNode -> previous != NULL) {
		curNode = curNode -> previous;
	}
	
	//frees all nodes after start node
	while (curNode -> next != NULL) {
		Node* tempNode = curNode;
		curNode = curNode -> next;
		printf("Free %i\n", tempNode -> data);
		free(tempNode);
	}
	
	printf("Free %i\n", curNode -> data);
	//frees final node
	free(curNode);
	
}


	/* dont need this
	while (curNode -> previous!= NULL && curNode -> next != NULL) { //should only stop at end??
		curNode = curNode -> next;
	}
	
	stopAt = (curNode -> location); //stops at start index if start node is passed as arg
	printf("Stop %i\n", stopAt);
	curNode = curNode -> next; //dont work
	*/
