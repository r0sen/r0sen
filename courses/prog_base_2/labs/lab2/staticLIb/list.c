#include "list.h"

struct list_s
{
    int  *ptr;
    int size;
};



list_t * list_newList()
{
    list_t * list = malloc(sizeof(list_t));
    list->ptr = malloc(MAX_SIZE * sizeof(int));
    list->size = 0;
    return list;
}

void list_freeList(list_t * list)
{
    free(list->ptr);
    free(list);
}

void list_add(list_t * list, int value)
{
    if((value < -128) || (value > 127 )|| (list_isFull(list)) )
        return;
	else
    list->ptr[list->size++] = value;
}

int list_deleteElement(list_t * list)
{
    if(list_isEmpty(list))
        return;
	else
    return list->ptr[list->size-1];
}

void list_output(list_t * list)
{
    int i;
    printf("\nList : \n");
    for(i = 0; i<list->size; i++)
        printf("%i   ", list->ptr[i]);

}

int list_callData(list_t * list, int index)
{
    if(list_isEmpty(list) || index < 0 || index >= list->size)
        return;
	else
    return list->ptr[index];
}

int list_callSize(list_t * list)
{
    return list->size;
}

int list_isEmpty(list_t * list)
{
    return 0 == list->size;
}

int list_isFull(list_t * list)
{
    return MAX_SIZE == list->size;
}
