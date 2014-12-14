#include "linked_s.h"
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const SIZE = 25; //using 100 for dev, TODO: normally allow user input?
const testStrLen = 1;
const testNoWords = 10;

void testPrintRandomStringAndHash() {
	int i; int j; int r;
	Node** table;
	
	table = initialise_hash_table();
	
	/* Seed for rand() based on time */
	srand(time(NULL)); 
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < testNoWords; i++) {
		char* string = malloc(testStrLen * sizeof(char) + 1);
		for (j = 0; j < testStrLen; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		string[testStrLen] = '\0';
		printf("string: %s with hash:%d \n", string, hashGetHashModK(string, SIZE));
		free(string);
	}
}

void testPrintRandomHashedStrings() {
	int i; int j; int r;
	Node** table;
	
	table = initialise_hash_table();
	
	/* Seed for rand() based on time */
	srand(time(NULL)); 
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	/* Generates random string */
	for (i = 0; i < testNoWords; i++) {
		char* string = malloc(testStrLen * sizeof(char) + 1);
		for (j = 0; j < testStrLen; j++) {
			r = rand() % 26;
			string[j] = alphabet[r];
		}
		string[testStrLen] = '\0';
		printf("string: %s with hash:%d \n", string, hashGetHashModK(string, SIZE));
		hashAddString(table, string);
		free(string);
	}
	
	for (i = 0; i < SIZE; i++) {
		printf("%i: \n", i);
		linkedPrintList(table[i]);
		printf("\n");
	} 
	hashClearTable(table);
}


/* Function creates the hash table - ie array of strings */
Node** initialise_hash_table() {
	//Node** table = calloc(SIZE,sizeof(Node*));
	Node** table = calloc(SIZE,sizeof(Node*));
	return table;
}

/* Function calculates hash of a string and then adds it to the table */
void hashAddString(Node** table, char* str) {
	unsigned long hash = hashGetHashModK(str, SIZE);
	
	/* Found element currently in table here */
	if (table[hash]) { 
		linkedAddItem(table[hash], str);
		printf("Added item to hash %d \n", hash);
	/* No element in this bucket - create a linked list */
	} else {
		table[hash] = linkedCreateList(str);
		printf("Created string %s and list at hash: %d \n", str, hash);
	}
}

/* 
	Function calculates hash of string and then removes it form table if it exists 
	Removes first if there are duplicates.
*/
void hashRemoveString(Node** table, char* str) {
	
	unsigned long hash = hashString(str);
	Node* list = table[hash];
	
	Node* matchNode = linkedFindNodeWithVal(list, str);
	if (!matchNode) {
		printf("Couldn't remove node with data: %s \n", str);
		return;
	}
	
	linkedRemoveNode(matchNode);
	/* TODO: Create remove node with value in linked_list? */
}

/* 
	Function finds if the table already has this value hashed
	returns 0 if true, 1 if false
*/
int hashIsHashed(Node** table, char* str) {
	unsigned long hash = hashGetHashModK(str, SIZE);
	Node* list = table[hash];
	
	/* Find node with value returns NULL if no matching node found else returns (Node*) */
	if (linkedFindNodeWithVal(list, str)) {
		return 0;
	}
	return 1; 
}

/* Required? Then add set hash? */
void hashRemoveHash(Node** table, unsigned long hash) {

}

int hashClearTable(Node** table) {
	int i;
	
	/* Failure */
	if (!table) {
		printf("Trying to clear invalid null table \n");
		return 1;
	}
	
	/* Loops through table cleaning lists when can */
	for (i = 0; i < SIZE; i++) {
		linkedCleanList(table[i]);
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

unsigned long hashGetHashModK(unsigned char* str, long k) {
	return (hashString(str)%k);
}