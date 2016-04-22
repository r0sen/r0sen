#ifndef LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 30

typedef struct list_s list_t;
list_t * list_new(int size);
void list_FillRandom(list_t * list, unsigned max);
void list_output(list_t * list);
void list_clear(list_t ** list);
int list_length(list_t * list);
int list_addNew(list_t * list , int index , int elem);
int list_deleteElement(list_t * list , int index);
int list_counter_positive(list_t * list);
int list_counter_null(list_t * list);
int list_counter_negative(list_t * list);


#endif
