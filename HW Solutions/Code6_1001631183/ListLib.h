//Yunika Upadhayaya  1001631183

#ifndef _LISTLIB_H
#define _LISTLIB_H

#define MAX_NUM 15

typedef struct node
{
    char Letter;
    char draw_command[MAX_NUM];
    struct node *next_ptr;
} node;

void InsertNewNode (char draw_letter, char draw_commands[],struct node **LinkedListHead);
void Find_LinkedList (struct node **book_mark, char draw_commands[],char new_char);

#endif

