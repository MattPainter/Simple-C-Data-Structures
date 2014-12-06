#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include 'linked_s.h'

unsigned long hashString(unsigned char*);
unsigned long getHashModK(unsigned char*, long);
void addString(Node**, char*); 			void removeString(Node**, char*);
void testPrintRandomStringAndHash(); 	void addString(Node**, char*);
void removeString(Node**, char*); 
Node** initialise_hash_table();

const SIZE = 100; //using 100 for dev, TODO: normally allow user input?

int main(int argc, char* argv) {
	testPrintRandomStringAndHash();
}

void testPrintRandomStringAndHash() {
	int i; int j;int r;
	
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
		printf("string: %s with hash:%d \n", string, getHashModK(str, SIZE));
		free(string);
	}
}

/* Function creates the hash table - ie array of strings */
Node** initialise_hash_table() {
	Node** table = malloc(sizeof(Node*)*SIZE);
	return table;
}

/* Function calculates hash of a string and then adds it to the table */
void addString(Node** table, char* str) {
	unsigned long hash = getHashModK(str, SIZE);
	Node* bucket = table[hash];
	
	/* Found element currently in table here */
	if (!bucket) { 
		addItem(bucket, str);
	/* No element in this bucket - create a linked list */
	} else{
		bucket = createList(str);
	}
}

/* Function calculates hash of string and then removes it form table if it exists */
void removeString(Node** table, Node* str) {
	unsigned long hash = hashString(str -> data);
	Node* list = table[hash];
	
	/* Remove node or str?? */
	removeNode(list, str);
	/* TODO: Create remove node with value in linked_list? */
}

int clearTable(Node** table) {
	
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