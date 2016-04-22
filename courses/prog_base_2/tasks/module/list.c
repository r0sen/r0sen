#include "list.h"
#include "time.h"




struct list_s{
	int *list;
	int size;
};

list_t * list_new(int size) {
	if (size <= 0 || size >= MAX_SIZE)
		return NULL;
    list_t * self = malloc(sizeof(struct list_s));
    self->list = malloc( size  * sizeof(int));
    self->size = size;
    return self;
}

void list_FillRandom(list_t * list, unsigned max){
	int i;
	for(i = 0; i < list->size; i++)
		list->list[i] = rand() % max;

}

int list_length(list_t * list)
{
	return list->size;
}



void list_clear(list_t ** list){

	free((*list)->list);
	free(*list);
	*list = NULL;
}
int list_deleteElement(list_t * list , int index){
    if(index < 0 || index >= list->size)
    {
        printf("\nNo element in that position\n");
        return 0;
    }
    int i;
    for(i = index; i <= list->size - 1; i++)
    {
        list->list[i] = list->list[i+1];
    }
    list->size--;
    return 0;
}

int list_addNew(list_t * list, int index , int elem ){

if(index > list->size || index < 0){
	return 1;
}
if(list->size+1 >= MAX_SIZE){
    return 0;
}
if(index == list->size){
    list->size++;
    list->list[index] = elem;
}
else{
    int i;
    list->size++;
    for(i = list->size-1; i >= index; i--){
        list->list[i+1] = list->list[i];
    }
    list->list[index] = elem;
}
return 0;
}



int list_counter_null(list_t * list){
    int i;
    int counter = 0;
    for(i = 0; i < list->size; i++){
        if(list->list[i] == 0)
            counter++;
    }
    return counter;
}
int list_counter_positive(list_t * list){
    int i;
    int counter = 0;
    for(i = 0; i < list->size; i++){
        if(list->list[i] > 0)
            counter++;
    }
    return counter;
}

int list_counter_negative(list_t * list){
    int i;
    int counter = 0;
    for(i = 0; i < list->size; i++){
        if(list->list[i] < 0)
            counter++;
    }
    return counter;
}
void list_output(list_t * list){
	int i;
	for(i = 0 ; i < list->size; i++)
		printf ("%i ", list->list[i]);
	printf("\n");
}

