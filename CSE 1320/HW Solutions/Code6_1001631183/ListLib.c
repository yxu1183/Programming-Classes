//Yunika Upadhayaya  1001631183

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListLib.h"

void InsertNewNode(char draw_letter, char draw_commands[], struct node **LinkedListHead)
{
    struct node *TempPtr, *new_node;
    new_node = malloc(sizeof(node));
    strcpy(new_node->draw_command, draw_commands);
    new_node->Letter = draw_letter;
    new_node->next_ptr = NULL;

    if (*LinkedListHead == NULL)
    {
        *LinkedListHead = new_node;
    }
    else
    {
        TempPtr = *LinkedListHead;
        while (TempPtr->next_ptr != NULL)
        {
            TempPtr = TempPtr->next_ptr;
        }
        TempPtr->next_ptr = new_node;
    }
}

void  Find_LinkedList(struct node **book_mark, char draw_command[], char new_char)
{
    struct node *TempPtr = *book_mark;
    if (TempPtr != NULL)
    {
        if (TempPtr->Letter == new_char)
        {
            strcpy(draw_command, TempPtr->draw_command);
        }
        *book_mark = TempPtr->next_ptr;
    }
}


