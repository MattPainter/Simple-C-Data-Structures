#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "linked_s.h"

unsigned long hashString(unsigned char*);
unsigned long getHashModK(unsigned char*, long);
void addString(Node**, char*); 			void removeString(Node**, char*);
void testPrintRandomStringAndHash(); 	void addString(Node**, char*);
void removeString(Node**, char*); 		void removeHash(Node**, unsigned long);
void testPrintRandomHashedStrings();
Node** initialise_hash_table();

const SIZE = 10; //using 100 for dev, TODO: normally allow user input?

int main(int argc, char* argv) {
	testPrintRandomHashedStrings();
	printf("Amazing\n");
}

void testPrintRandomStringAndHash() {
	int i; int j;int r;
	Node** table;
	
	table = initialise_hash_table();
	
	/* Seed for rand() based on time */
	srand(time(NULL)); 
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < 10; i++) {
		unsigned char* string = malloc(10 * sizeof(char));
		for (j = 0; j < 10; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		printf("string: %s with hash:%d \n", string, getHashModK(string, SIZE));
		free(string);
	}
}

void testPrintRandomHashedStrings() {
	int i; int j;int r;
	Node** table;
	
	table = initialise_hash_table();
	
	/* Seed for rand() based on time */
	srand(time(NULL)); 
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < 5; i++) {
		unsigned char* string = malloc(10 * sizeof(char));
		for (j = 0; j < 10; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		printf("string: %s with hash:%d \n", string, getHashModK(string, SIZE));
		addString(table, string);
		free(string);
	}
	
	printf("\n Now the fun begins \n");
	
	for (i = 0; i < SIZE; i++) {
		printf("%i: \n", i);
		printList(table[i]);
		printf("\n");
	}	
	
	clearTable(table);
}


/* Function creates the hash table - ie array of strings */
Node** initialise_hash_table() {
	Node** table = malloc(sizeof(Node*)*SIZE);
	return table;
}

/* Function calculates hash of a string and then adds it to the table */
void addString(Node** table, char* str) {
	unsigned long hash = getHashModK(str, SIZE);
	
	/* Found element currently in table here */
	if (table[hash]) { 
		addItem(table[hash], str);
		printf("Added item to hash %d \n", hash);
	/* No element in this bucket - create a linked list */
	} else {
		table[hash] = createList(str);
		printf("Created string %s and list at hash: %d \n", str, hash);
	}
}

/* Function calculates hash of string and then removes it form table if it exists */
void removeString(Node** table, char* str) {
	unsigned long hash = hashString(str);
	Node* list = table[hash];
	
	Node* matchNode = findNodeWithVal(list, str);
	if (!matchNode) {
		printf("Couldn't remove node with data: %s \n", str);
		return;
	}
	
	removeNode(matchNode);
	/* TODO: Create remove node with value in linked_list? */
}

/* Required? */
void removeHash(Node** table, unsigned long hash) {

}

int clearTable(Node** table) {
	int i;
	
	/* Failure */
	if (!table) {
		printf("Trying to clear invalid null table \n");
		return 1;
	}
	
	/* Loops through table cleaning lists when can */
	for (i = 0; i < SIZE; i++) {
		cleanList(table[i]);
	}
	
	/* Success */
	free(table);
	return 0;
}

/*  
    Hash function as defined in djb2 algorithm for hashing strings 
    returns between 0 and 16^6
*/
unsigned long hashString(unsigned char* str) {
	unsigned long hash = 5381;
	int c;
	
	while (c = *str++) {
		/* hash * 33 + c */
		hash = ((hash << 5) + hash) + c; 
	}
	return (hash & 0xFFFFFF);
}

unsigned long getHashModK(unsigned char* str, long k) {
	return (hashString(str)%k);
}