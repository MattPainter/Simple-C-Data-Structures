typedef int stackT;

typedef struct Stack {
	int head;
	stackT* stack;
	int size;
} stack;

stack* init_stack(int size);
stackT* stackPop(stack* s);
int stackPush(stack* s, stackT data);
stackT* stackPeek(stack* s);
void stackClear(stack* s);