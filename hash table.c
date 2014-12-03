#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long hashString(unsigned char*);
void addString(char**, char*); 			void removeString(char**, char*);
void testPrintRandomStringAndHash(); 	void addString(char**, char*);
void removeString(char**, char*);
char** initialise_hash_table();

const SIZE = 100;

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
		printf("string: %s with hash:%d \n", string, hashString(string)%100);
		free(string);
	}
}

/* Function creates the hash table - ie array of strings */
char** initialise_hash_table() {
	char** table = malloc(sizeof(char*)*SIZE) /* For development, use 100 buckets */
	return table;
}

/* Function calculates hash of a string and then adds it to the table */
void addString(char** table, char* str) {
	unsigned long hash = hashString(str) % SIZE;
	int len = 0; int i = 0;
	while(str[i]) {
		len++; i++;
	}
	len++; /* Extra end line char */
	/* Check for collisions here */
	table[hash] = malloc(sizeof(char)*len);
	strcopy(table[hash], str);
	
}

/* Function calculates hash of string and then removes it form table if it exists */
void removeString(char** table, char* str) {
	unsigned long hash = hashString(str);
	
}

int clearTable(char** table) {
	
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