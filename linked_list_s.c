#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_s.h"

/*
  Program implements a double linked list of strings and can be used by
  including linked_s.h in file and compiling with linked_list_s.c
  gcc linked_list_s.c linked_test_s.c
*/

/* now test via linked_test_s.c via gcc linked_list_s.c linked_test_s.c -o...
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

/* Creates the first item in list */
Node* createList(char* data) {
	Node* startPtr = (Node*)malloc(sizeof(Node));
	if (startPtr == NULL) {
		printf("NULL PTR EXCEPTION");
	}
	
	startPtr -> data = malloc(strlen(data)+1);
	if (startPtr -> data == NULL){ 
		printf("NULL PTR EXCEPTION");
	}
	
	strcpy(startPtr -> data, data);
	startPtr -> next = NULL;
	startPtr -> previous = NULL;
	
	return startPtr;
}

/* Adds an item to the list and sets previous pointer to it */
void addItem(Node* list, char* data) {
	Node* oldEndPtr = list;
	Node* newPtr = malloc(sizeof(Node)); 
	if (newPtr == NULL) {
		printf("NULL PTR EXCEPTION");
		exit(1);
	}
	
	/* Finds if only one node */
	if (((oldEndPtr -> previous) == NULL) && ((oldEndPtr -> next) == NULL)) {
	} else {
		/* Loops to end node */
		while (oldEndPtr -> next != NULL) {
			oldEndPtr = oldEndPtr -> next;
		}
	}
	
	/* Creates new node */
	newPtr -> data = malloc(strlen(data)+1);
	if (newPtr -> data == NULL){ 
		printf("NULL PTR EXCEPTION");
		exit(1);
	}
	strcpy(newPtr -> data, data);
	newPtr -> next = NULL;
	newPtr -> previous = oldEndPtr; 
	
	oldEndPtr -> next = newPtr;
}

/* Point to item after given */
Node* getItemAfter(Node* currentItem) {
	if (currentItem -> next == NULL) {
		return NULL; 
	} else {
		return (currentItem -> next);
	}
}

/* 
	Searches linked list for node with value val 
	If not found, returns null
*/
Node* findNodeWithVal(Node* list, char* val) {
	/* Navigate to start - could lower time by searching along way */
	if (list -> previous) {
		list = list -> previous;
	}
	
	while (list -> next) {
		if (strcmp(list -> data, val) == 0) {
			return list;
		}
	} 
	return NULL;
	
}

/* Removes a given Node */
Node* removeNode(Node* badNode) {
	Node* previousNode = badNode -> previous;
	Node* nextNode = badNode -> next; 
	
	if (!(previousNode && nextNode)) {
		cleanList(badNode);
	}
	
	/* Moves pointers to avoid badNode */
	previousNode -> next = nextNode; 
	nextNode -> previous = previousNode; //if no prev, should go NULL as required. TODO check
	
	free(badNode);
	return(previousNode);
}

/* TODO: create remove node with value? */

/* Print list of all nodes in structure */
void printList(Node* list) {
	if (!list) {
		printf("Can't print null list \n");
		return;
	}

	Node* curNode = list;
	int i = 0;
	
	/* Finds start node */
	while (curNode -> previous != NULL) {
		curNode = curNode -> previous;
	}
	
	/* Loops over nodes and prints */
	while (curNode -> next != NULL) {
		printf("Node %i - value %s \n", i++, curNode -> data);
		curNode = curNode -> next;
	}
	
	/* Prints final node */
	printf("Node %i - value %s \n", i, curNode -> data);
}

/* Attempts to free all allocated memory, run a valgrind on it */
void cleanList(Node* start) {
	Node* curNode = start;
	
	if (!start) {
		return;
	}
	
	/* Finds start node if not passed as arg*/
	while (curNode -> previous != NULL) {
		curNode = curNode -> previous;
	}
	
	/* Frees all nodes after start node */
	while (curNode -> next != NULL) {
		Node* tempNode = curNode;
		curNode = curNode -> next;
		printf("Free %s\n", tempNode -> data);
		free(tempNode);
	}
	
	/* Frees final node */
	printf("Free %s\n", curNode -> data);
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
