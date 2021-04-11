#include "scheduler.h"

Node* ReadyQ;
NodeD* DelayedQ;
fptr CurrentTaskAddress;
int CurrentTaskPriority;

void Init(void)
{
    ReadyQ = (Node*)malloc(sizeof(Node));
    DelayedQ = (NodeD*)malloc(sizeof(NodeD));
    ReadyQ = NULL;
    DelayedQ = NULL;
}

void QueTask(fptr f, int p)
{
    push(&ReadyQ, f, p);
}

void ReRunMe(int d)
{
    fptr f = CurrentTaskAddress;
    int p = CurrentTaskPriority;
    pushD(&DelayedQ, f, p, d);
}

void Dispatch(void)
{
	if(PendingTasks())
	{
			Node* CurrentTask = peek(&ReadyQ);
			CurrentTaskAddress = CurrentTask->fn;
			CurrentTaskPriority = CurrentTask->priority;
			pop(&ReadyQ);
			(*CurrentTaskAddress)();
	}

}

void DecreasePriorities(void)
{
    NodeD* start = DelayedQ;
    while(start != NULL)
    {
        start->delay = start->delay-1;
        start = start->next;
    }
    while (DelayedQ->delay == 0)
    {
        NodeD* ReadyTask = peekD(&DelayedQ);
        fptr f = ReadyTask->fn;
        int p = ReadyTask->priority;
        push(&ReadyQ, f, p);
			  popD(&DelayedQ);
    }
        
}

int PendingTasks(void)
{
    return !isEmpty(&ReadyQ);
}
