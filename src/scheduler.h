#ifndef SCHEDULER_FILE
#define SCHEDULER_FILE

#include "rqueue.h"
#include "dqueue.h"

void Init(void);
void QueTask(fptr f, int p);
void ReRunMe (int d);
void Dispatch(void);
void DecreasePriorities(void);
int PendingTasks(void); //to return whether there are pending tasks or not

#endif
