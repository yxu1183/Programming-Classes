/*Yunika Upadhayaya 1001631183*/

#ifndef _SORTLIB_H
#define _SORTLIB_H

typedef struct 
{
    char name[50];
    char sandwich[50];
    char fry_size;
    char drink_size;
    char drink_type[50];
}Combos;

int name_Compare(const void *, const void *);
int sandwich_Compare(const void *, const void *);
int frysize_Compare(const void *, const void *);
int drinksize_Compare(const void *, const void *);
int drinktype_Compare(const void *, const void *);

#endif

