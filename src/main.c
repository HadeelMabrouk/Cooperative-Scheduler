#include <stdio.h>
#include <stdlib.h>
#include "rqueue.h"
#include "dqueue.h"

Node* ReadyQ;
NodeD* DelayedQ;
Node* CurrentTask;

void Init(void);
void QueTask(fptr f, int p);
void ReRunMe (int d);
void Dispatch();
void DereasePriorities();
int PendingTasks(); //to return whether there are pending tasks or not


void f1(void);
void f2(void);
void f3(void);

void Init()
{
    ReadyQ = (Node*)malloc(sizeof(Node));
    DelayedQ = (NodeD*)malloc(sizeof(NodeD));
    CurrentTask = (Node*)malloc(sizeof(Node));
    ReadyQ = NULL;
    DelayedQ = NULL;
}

void QueTask(fptr f, int p)
{
    push(&ReadyQ, f, p);
}

void ReRunMe(int d)
{
    fptr f = CurrentTask->fn;
    int p = CurrentTask->priority;
    pushD(&DelayedQ, f, p, d);
}

void Dispatch()
{
    CurrentTask = peek(&ReadyQ);
    fptr e = CurrentTask->fn;
    pop(&ReadyQ);
    (*e)();
}

void DereasePriorities()
{
    NodeD* start = DelayedQ;
    while(start->next != NULL)
    {
        start->delay--;
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
