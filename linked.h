/* Struct for a Node which contains a int value and pointers to previous and next node */
typedef struct node {
	int data; 
	struct node* next;
	struct node* previous;
} Node;

/* Function declarations for functions in linked_list.c */
void addItem(Node* list, int data); void cleanList(Node*); void printList(Node*);
Node* createList(int); Node* getItemAfter(Node*); Node* removeNode(Node*);