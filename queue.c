#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_s.h"
#include "queue.h"

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






