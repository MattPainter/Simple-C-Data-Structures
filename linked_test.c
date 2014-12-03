#include "linked.h"
#include <stdio.h>

int main(int argc, char** argv) {
	int i = 0; 
	Node* nextOne;
	Node* test = createList(3);
	for (i = 0; i < 10; i++) {
		addItem(test, i);
	}
	
	printf("TESTING - %i \n", test -> data);
	printList(test);
	printf("Break\n");
	removeNode(test -> next);
	printf("Break \n");
	cleanList(test);
	printf("TESTING - end");
	return 0;
}