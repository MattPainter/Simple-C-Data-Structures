/* Struct for a Node which contains a string value and pointers to previous and next node */
typedef struct node {
	char* data; 
	struct node* next;
	struct node* previous;
} Node;

/* Function declarations for functions in linked_list.c */
void linkedAddItem(Node* list, char* data); void linkedCleanList(Node*); void linkedPrintList(Node*);
Node* linkedCreateList(char*); Node* linkedGetItemAfter(Node*); Node* linkedRemoveNode(Node*);
Node* linkedFindNodeWithVal(Node* list, char* val);