// Name: Yunika Upadhayaya    Student ID: 10016631183 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListLib.h"

void InsertNode(LNODE **LinkedListHead, char info_Seat[])
{
   LNODE *TempPtr, *PrevPtr, *NewNode;
   
   PrevPtr = NULL;
   TempPtr = *LinkedListHead;
   
   while (TempPtr != NULL && strcmp(TempPtr->Ticket,info_Seat)<0)
  {
     PrevPtr = TempPtr;
     TempPtr = TempPtr->next_ptr;
  }
  
  NewNode = malloc(sizeof(LNODE));
  strcpy(NewNode->Ticket,info_Seat);
  NewNode->next_ptr = TempPtr;
  
  if (PrevPtr == NULL)
  {
     *LinkedListHead = NewNode;
  }
  
  else
  {
     PrevPtr->next_ptr = NewNode;
  }
}

void ReturnAndFreeLinkedListNode(LNODE **LinkedListHead, char info_Seat[])
{
	LNODE *TempPtr = *LinkedListHead;
	strcpy(info_Seat, TempPtr->Ticket);
	free(*LinkedListHead);
	*LinkedListHead = TempPtr->next_ptr;
}

