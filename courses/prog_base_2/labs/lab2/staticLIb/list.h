#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct list_s list_t;

list_t * list_newList();
void list_freeList(list_t * list);

void list_add(list_t * list, int value);

int list_deleteElement(list_t * list);

int list_callData(list_t * list, int index);

int list_callSize(list_t * list);

void list_output(list_t * list);

int list_isEmpty(list_t * list);

int list_isFull(list_t * list);

#endif // LIST_H_INCLUDED
