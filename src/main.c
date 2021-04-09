#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node* ReadyQ;
Node* DelayedQ;

void Dispatch();
void QueTask(fptr f, int p);
void Init(void);
void DereasePriorities();
int PendingTasks(); //to return whether there are pending tasks or not

void f1(void);
void f2(void);
void f3(void);


void Dispatch()
{
    fptr e;
    e = peek(&ReadyQ);
    pop(&ReadyQ);
    (*e)();
}

void QueTask(fptr f, int p)
{
    push(&ReadyQ, f, p);
}

void Init()
{
    ReadyQ = (Node*)malloc(sizeof(Node));
    DelayedQ = (Node*)malloc(sizeof(Node));
    ReadyQ = NULL;
    DelayedQ = NULL;
}

void DereasePriorities()
{
    Node* start = DelayedQ;
    while(start->next != NULL)
    {
        start->priority--;
        start = start->next;
    }
}

int PendingTasks()
{
    return !isEmpty(&ReadyQ);
}
 
 
void f1(void) {
    printf("1\n");
}
void f2(void) {
    printf("2\n");
}
void f3(void) {
    printf("3\n");
}
// Driver code
int main()
{
    // Create a Priority Queue
    // fn1->fn2->fn3
    Init();
        
    QueTask(f1, 1);
    QueTask(f2, 2);
    QueTask(f3, 3);
    

  while (PendingTasks()) {
        Dispatch();
    }
    return 0;
}
