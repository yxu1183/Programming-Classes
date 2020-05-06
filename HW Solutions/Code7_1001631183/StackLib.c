//Name: Yunika Upadhayaya   Student ID: 1001631183

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackLib.h"

void push(SNODE **top_stack, LNODE *LinkedListHead, int receipt_num, char theatre_name[])
{	
    SNODE *NewNode = malloc(sizeof(SNODE));
    NewNode->TicketList = LinkedListHead;
	NewNode->ReceiptNumber = receipt_num;
	strcpy(NewNode->MovieTheaterName,theatre_name);
	NewNode->next_ptr=NULL;
	
	if (*top_stack == NULL)
	{
		(*top_stack) = NewNode;
		NewNode->next_ptr = NULL;
	}
	else
	{
		NewNode->next_ptr = *top_stack;
		*top_stack = NewNode;
    }	
}

void pop(SNODE **top_stack)
{
	SNODE *TempPtr = *top_stack;
	
    free(*top_stack);
    *top_stack = TempPtr->next_ptr;
	TempPtr = *top_stack;
	
}

