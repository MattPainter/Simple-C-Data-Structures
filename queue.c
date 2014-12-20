#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_s.h"

/* Changes here require changes to included linked lists file */
typedef char queueT;
typedef Node Queue;

Queue* init_queue();
void queuePrintQueue(Queue* queue);
queueT* queuePeek(Queue* queue);
void queueEnqueue(Queue* queue, queueT* data);
Queue* queueDequeue(Queue* queue);
int queueIsQueued(Queue* queue, queueT* data) ;
void queueCleanQueue(Queue* queue);

const testStrLen = 1;
const testNoWords = 10;

int main(int argc, char* argv) {
	int i, j; long r;
	Queue* q;
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < testNoWords; i++) {
		char* string = malloc(testStrLen * sizeof(char) + 1);
		for (j = 0; j < testStrLen; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		string[testStrLen] = '\0';
		
		queueEnqueue(q, string);
		queueT* temp = queuePeek(q);
		printf("%s \n", string);
		free(string);
	}
	
	queuePrintQueue(q);
	printf("\n");
	q = queueDequeue(q);
	queuePrintQueue(q);
}

Queue* init_queue() {
	Queue* nullNode = linkedCreateList(NULL);
	return nullNode;
}

void queuePrintQueue(Queue* queue) {
	linkedPrintList(queue);
}

queueT* queuePeek(Queue* queue) {
	return linkedPeek(queue); //TODO: create peek in linked list
}

void queueEnqueue(Queue* queue, queueT* data) {
	if (queue -> data == NULL) {
		/* Bad compromise */
		queue -> data = malloc(strlen(data)+1);
		strcpy(queue -> data, data);
	} else {
		linkedAddItem(queue, data);
	}
}

Queue* queueDequeue(Queue* queue) {
	if (!queue) {
		return NULL; 
	} else {

		return 	linkedRemoveNode(queue);
	}
}

/* Returns 0 if value is queued found, 1 else */
int queueIsQueued(Queue* queue, queueT* data) {
	if (linkedFindNodeWithVal(queue, data)) {
		return 0;
	} 
	return 1; 
}

void queueCleanQueue(Queue* queue) {
	linkedCleanList(queue);
}






