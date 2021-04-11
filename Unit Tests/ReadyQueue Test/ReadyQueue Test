#include "scheduler.h"
 
 
void t1(void) {
    printf("1\n");
}
void t2(void) {
    printf("2\n");
}
void t3(void) {
    printf("3\n");
}
// Driver code
int main()
{
    // Create a Priority Queue
    // tn1->tn2->tn3
    Init();
        
    QueTask(t1, 1);
    QueTask(t2, 2);
    QueTask(t3, 3);
    

  while (1) 
  {
        Dispatch();
  }
  return 0;
}
