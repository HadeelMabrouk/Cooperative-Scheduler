#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

 
 
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
    Node* pq = newNode(f1, 1);
    push(&pq, f2, 2);
    push(&pq, f3, 3);
 
    fptr e;
    while (!isEmpty(&pq)) {
        e = peek(&pq);
        (*e)();
        pop(&pq);
    }
 
    return 0;
}
