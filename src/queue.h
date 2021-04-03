#ifndef HEADER_FILE
#define HEADER_FILE

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
fptr peek(Node** head);
void pop(Node** head);
void push(Node** head, fptr f, int p);
int isEmpty(Node** head);


void f1(void);
void f2(void);
void f3(void);

// Function to Create A New Node
Node* newNode(fptr f, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->fn = f;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 
// Return the value at head
fptr peek(Node** head)
{
    return (*head)->fn;
}
 
// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
// Function to push according to priority
void push(Node** head, fptr f, int p)
{
    Node* start = (*head);
 
    // Create new Node
    Node* temp = newNode(f, p);
 
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {
 
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
 
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
            start->next->priority < p) {
            start = start->next;
        }
 
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}
 
// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

#endif
 
