typedef char queueT;
typedef Node Queue;

Queue* init_queue();
void queuePrintQueue(Queue* queue);
queueT* queuePeek(Queue* queue);
void queueEnqueue(Queue* queue, queueT* data);
Queue* queueDequeue(Queue* queue);
int queueIsQueued(Queue* queue, queueT* data) ;
void queueCleanQueue(Queue* queue);