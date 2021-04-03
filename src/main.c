#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Dispatch(Node** head);
void QueTask(Node** head,fptr f, int p);
Node* Init(void);


void Dispatch(Node** head)
{
    fptr e;
    e = peek(head);
    pop(head);
    (*e)();
}

void QueTask(Node** head,fptr f, int p)
{
    push(head, f, p);
}

Node* Init(void)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp = NULL;
    
    return temp;
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
    Node* pq = Init();
        
    QueTask(&pq, f1, 1);
    QueTask(&pq, f2, 2);
    QueTask(&pq, f3, 3);
    

  while (!isEmpty(&pq)) {
        Dispatch(&pq);
    }
    return 0;
}
