#ifndef RQUEUE_FILE
#define RQUEUE_FILE

// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>
 
// Node
typedef void (*fptr)(void);

typedef struct node {
    
	  fptr fn;
    // Lower values indicate higher priority
    int priority;
 
    struct node* next;
 
} Node;
 

Node* newNode(fptr f, int p);
Node* peek(Node** head);
void pop(Node** head);
void push(Node** head, fptr f, int p);
int isEmpty(Node** head);


#endif
