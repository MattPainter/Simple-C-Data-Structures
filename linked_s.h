/* Struct for a Node which contains a string value and pointers to previous and next node */
typedef struct node {
	char* data; 
	struct node* next;
	struct node* previous;
} Node;

/* Function declarations for functions in linked_list.c */
void addItem(Node* list, char* data); void cleanList(Node*); void printList(Node*);
Node* createList(char*); Node* getItemAfter(Node*); Node* removeNode(Node*);