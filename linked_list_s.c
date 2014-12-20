#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_s.h"

/*
  Program implements a double linked list of strings and can be used by
  including linked_s.h in file and compiling with linked_list_s.c
  gcc linked_list_s.c linked_test_s.c
*/

/* 
	Now test via linked_test_s.c via gcc linked_list_s.c linked_test_s.c -o...
*/

/* Creates the first item in list */
Node* linkedCreateList(char* data) {
	Node* startPtr = (Node*)malloc(sizeof(Node));
	if (startPtr == NULL) {
		printf("NULL PTR EXCEPTION");
		exit(1);
	}
	
	startPtr -> data = malloc(strlen(data)+1);
	if (startPtr -> data == NULL){ 
		printf("NULL PTR EXCEPTION");
		exit(1);
	}
	
	strcpy(startPtr -> data, data);
	startPtr -> next = NULL;
	startPtr -> previous = NULL;
	
	return startPtr;
}

/* Adds an item to the list and sets previous pointer to it */
void linkedAddItem(Node* list, char* data) {
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
Node* linkedGetItemAfter(Node* currentItem) {
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
Node* linkedFindNodeWithVal(Node* list, char* val) {
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
Node* linkedRemoveNode(Node* badNode) {
	Node* previousNode = badNode -> previous;
	Node* nextNode = badNode -> next; 
	
	if ((previousNode == NULL && nextNode == NULL)) {
		linkedCleanList(badNode);
	}
	
	/* Moves pointers to avoid badNode */
	nextNode -> previous = previousNode; //if no prev, should go NULL as required. TODO check
	if (previousNode) {
		previousNode -> next = nextNode; 
		free(badNode);
		return(previousNode);
	} else {
		/* If removing the first node, then this should return the original second node */
		linkedCopyNode(badNode, nextNode);
		free(nextNode);
		return badNode;
	}
	
	return NULL;
}

/* TODO: create remove node with value? */

/* Print list of all nodes in structure */
void linkedPrintList(Node* list) {
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
void linkedCleanList(Node* start) {
	Node* curNode = start;
	
	if (!start) {
		return;
	}
	
	/* Finds start node if not passed as arg (start) */
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

char* linkedPeek(Node* list) {
	return (list -> data);
}

void linkedCopyNode(Node* destination, Node* source) {
	strcpy(destination -> data, source -> data);
	destination -> previous = source -> previous;
	destination -> next = source -> next; 
}
