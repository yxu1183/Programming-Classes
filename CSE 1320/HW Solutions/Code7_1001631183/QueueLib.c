/* Name: Yunika Upadhayaya      Student ID: 1001631183 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QueueLib.h"

void enQueue(char customers_name[],QNODE **head_queue, QNODE **head_tail)
{
	QNODE *NewNode = malloc(sizeof(QNODE));
    strcpy(NewNode->Name,customers_name);
	NewNode->next_ptr = NULL;

	if (*head_queue == NULL)
	{
		*head_queue = *head_tail = NewNode;
	}
	else
	{
		(*head_tail)->next_ptr = NewNode;
		*head_tail = NewNode;
	}
}

void deQueue(QNODE **head_queue)
{
	QNODE *TempPtr = (*head_queue)->next_ptr;
	
    if (*head_queue == NULL)
	{
		printf("Queue is empty\n\n");
	}
	
	else
	{
        free(*head_queue);
        *head_queue = TempPtr; 
    }
	
}

void DisplayQueue(QNODE *head_queue)
{
	QNODE *TempPtr = head_queue;

	if(TempPtr == NULL)
	{
		printf("No Customers\n");
	}
	
	else
	{
	    while (TempPtr != NULL)
       {
          printf("%s\n", TempPtr->Name);
          TempPtr = TempPtr->next_ptr;
       }
	}
}

