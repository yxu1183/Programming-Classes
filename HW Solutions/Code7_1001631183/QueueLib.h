//Name: Yunika Upadhayaya    Student Id: 1001631183

#ifndef _QUEUE_LIB_H
#define _QUEUE_LIB_H

typedef struct QNODE
{
    char Name[30];
    struct QNODE *next_ptr;
} QNODE;

// First parameter - Customer's name
// Second parameter - Address of QueueHead
// Third parameter - Address of QueueTail
void enQueue(char [], QNODE **, QNODE **);

// First parameter - Address of QueueHead
void deQueue(QNODE **);

// First parameter - QueueHead 
// Prints Name from the queue
void DisplayQueue(QNODE *);

#endif

