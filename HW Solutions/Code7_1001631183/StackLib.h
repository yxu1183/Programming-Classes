/*Name: Yunika Uapdhayaya  Student ID: 1001631183 */

#include "ListLib.h"

#ifndef _STACK_LIB_H
#define _STACK_LIB_H

typedef struct SNODE
{
    int ReceiptNumber;
	char MovieTheaterName[30];
	LNODE *TicketList;
    struct SNODE *next_ptr;
} SNODE;

// First parameter - Address of StackTop
// Second parameter - Head of ticket linked list stored in stack node 
// Third parameter - Receipt number stored in stack node
// Fourth parameter - Movie theater name stored in stack node
void push(SNODE **, LNODE *, int, char[]);

// First parameter - Address of StackTop
void pop(SNODE **);

#endif

