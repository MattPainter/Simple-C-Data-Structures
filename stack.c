#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* init_stack(int size) { //should use size_t?
	/* Initialise stack structure */
	stack* stackPtr = malloc(sizeof(stack));
	stackPtr -> head = -1;
	stackPtr -> stack = malloc(sizeof(stackT)*size);
	stackPtr -> size = size;
	
	return stackPtr;
}

/* Returns ptr to popped element */
stackT* stackPop(stack* s) {
	/* Empty stack */
	if ((s -> head) < 0) {
		return NULL;
	/* Some items in stack */
	} else {
		/* Store top item, then adjust head */
		stackT* popped = &(s -> stack)[(s -> head)];
		if ((s -> head) == 0) {
			(s -> head) = -1;
		} else {
			(s -> head)--;
		}
		return popped;
	}
}

/* Return 0 of success, 1 on fail */
int stackPush(stack* s, stackT data) {
	/* Empty stack */
	if ((s -> head) < 0) {
		/* Store data at start of array, point head here */
		(s -> stack)[0] = data;
		(s -> head) = 0;
	} else {
		/* Makes sure next head value wouldn't overflow the stack */
		if (++(s -> head) < (s -> size)) {
			(s -> stack)[(s -> head)] = data;
			return 0;
		/* Returns failure as of stack overflow */
		} else {
			return 1;
		}
	}
}

/* Returns ptr to top element on stack */
stackT* stackPeek(stack* s) {
	if ((s -> head) < 0) {
		return NULL;
	} else {
		return &(s -> stack)[(s -> head)];
	}
}

void stackClear(stack* s) {
	/* Frees both stack array and stack structure pointer */
	free(s -> stack);
	free(s);
}


/*
	TODO: dynamically resize stack array using realloc?
*/


