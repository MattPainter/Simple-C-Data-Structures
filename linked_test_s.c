#include "linked_s.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(int argc, char** argv) {
	int i = 0; int r; int j;
	Node* nextOne;
	Node* test = createList("Test");

	srand(time(NULL)); 
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < 10; i++) {
		unsigned char* string = malloc(10 * sizeof(char));
		for (j = 0; j < 10; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		printf("String: %s \n", string);
		addItem(test, string);
		free(string);
	}
	
	printf("TESTING - %s \n", test -> data);
	printList(test);
	printf("Break \n");
	removeNode(test -> next);
	printf("Break \n");
	cleanList(test);
	printf("TESTING - end");
	return 0;
}