#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "time.h"
#include <locale.h>

int main(void){
	srand(time(NULL));
	list_t * list = list_new(size);
    list_FillRandom(list, 100);
    list_output(list);
    list_addNew(list, 2, 17);
    list_output(list);
    list_deleteElement(list, 5);
    list_output(list);
    printf("Positive count: %i\n", list_counter_positive(list));
    printf("Negative count: %i\n", list_counter_negative(list));
    printf("Null count: %i\n", list_counter_null(list));
    list_clear(&list);
	return 0;
}
