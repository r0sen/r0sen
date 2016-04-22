#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "list.h"
#include "time.h"

static void new_void_size_two( void **state){

    list_t * list = list_new(2);
    assert_int_equal(list_length(list), 2);
    list_clear(&list);
}

static void new_int_add_two_on_sec_pos( void **state){

    list_t * list = list_new(2);
    assert_int_equal(list_addNew(list, 1, 2), 2);
    list_clear(&list);
}



static void new_int_list_positive_elements( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 10, 1);
    assert_int_equal(list_counter_positive(list), 2);
    list_clear(&list);
}
static void new_int_del_sec_element( void **state){
    list_t * list = list_new(2);
    list_addNew(list, 1, 2);
    assert_int_equal(list_deleteElement(list, 1), 0);
    list_clear(&list);
}
static void new_int_list_no_positive_elements( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 10, -50);
    assert_int_equal(list_counter_positive(list), 0);
    list_clear(&list);
}

static void new_int_list_all_negative_elements( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 100, -200);
    assert_int_equal(list_counter_negative(list), 2);
    list_clear(&list);
}

static void new_int_list_no_negative_elements( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 10, 2);
    assert_int_equal(list_counter_negative(list), 0);
    list_clear(&list);
}

static void new_int_list_no_zero( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 10, 1);
    assert_int_equal(list_counter_null(list), 0);
    list_clear(&list);
}

static void new_int_list_all_zero( void **state){
    list_t * list = list_new(2);
    list_FillRandom(list, 1, 0);
    assert_int_equal(list_counter_null(list), 2);
    list_clear(&list);
}



int main(void){

    srand(time(NULL));
    const UnitTest unitTests[] = {
        unit_test(new_void_size_two),
        unit_test(new_int_add_two_on_sec_pos),
        unit_test(new_int_list_positive_elements),
		unit_test(new_int_del_sec_element),
        unit_test(new_int_list_no_positive_elements),
        unit_test(new_int_list_all_negative_elements),
        unit_test(new_int_list_no_negative_elements),
		unit_test(new_int_list_no_zero),
        unit_test(new_int_list_all_zero)
    };
    return run_tests(unitTests);

}
