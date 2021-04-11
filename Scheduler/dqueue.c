#include "dqueue.h"

// Function to Create A New Node
NodeD* newNodeD(fptr f, int p, int d)
{
    NodeD* temp = (NodeD*)malloc(sizeof(NodeD));
    temp->fn = f;
    temp->priority = p;
    temp->delay = d;
    temp->next = NULL;
 
    return temp;
}
 
// Return the value at head
NodeD* peekD(NodeD** head)
{
    return (*head);
}
 
// Removes the element with the
// highest priority form the list
void popD(NodeD** head)
{
    NodeD* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
// Function to push according to priority
void pushD(NodeD** head, fptr f, int p, int d)
{
    NodeD* start = (*head);

    // Create new Node
    NodeD* temp = newNodeD(f, p, d);
 
    if(!isEmptyD(head))
    {
        // Special Case: The head of list has lesser
        // priority than new node. So insert new
        // node before head node and change head node.
        if ((*head)->delay > d) {
     
            // Insert New Node before head
            temp->next = *head;
            (*head) = temp;
        }
        else {
     
            // Traverse the list and find a
            // position to insert new node
            while (start->next != NULL &&
                start->next->delay < d) {
                start = start->next;
            }
     
            // Either at the ends of the list
            // or at required position
            temp->next = start->next;
            start->next = temp;
        }
    }
    else
    {
        (*head) = temp;
    }
    
}
 
// Function to check is list is empty
int isEmptyD(NodeD** head)
{
    return (*head) == NULL;
}
