#ifndef DQUEUE_FILE
#define DQUEUE_FILE

// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>
 
// Node
typedef void (*fptr)(void);

typedef struct nodeD {
    
	  fptr fn;
    // Lower values indicate higher priority
    int priority;
    int delay;
 
    struct nodeD* next;
 
} NodeD;
 

NodeD* newNodeD(fptr f, int p, int d);
NodeD* peekD(NodeD** head);
void popD(NodeD** head);
void pushD(NodeD** head, fptr f, int p, int d);
int isEmptyD(NodeD** head);


#endif
