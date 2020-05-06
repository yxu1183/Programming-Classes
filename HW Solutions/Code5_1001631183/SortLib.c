/*Yunika Upadhayaya 1001631183*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SortLib.h"


int name_Compare(const void *a, const void *b)
{
    return (strcmp(((Combos*)a)->name, ((Combos*)b)->name));
}

int sandwich_Compare(const void *a, const void *b)
{
    return (strcmp(((Combos*)a)->sandwich, ((Combos*)b)->sandwich));
}

int frysize_Compare(const void *a, const void *b)
{
    return (((Combos*)a)->fry_size > (((Combos*)b)->fry_size));
}

int drinksize_Compare(const void *a, const void *b)
{
    return (((Combos*)a)->drink_size > (((Combos*)b)->drink_size));
}

int drinktype_Compare(const void *a, const void *b)
{
    return (strcmp(((Combos*)a)->drink_type, ((Combos*)b)->drink_type));
}

