#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !
#include <cmocka_pbc.h>
#include <cmocka.h>




int checkNumberBase(char *numberInString, int base)
{
return (strtol(numberInString, NULL, base) != 0);
}


static void test_for_first(void **text){

    assert_int_equal(checkNumberBase("123",4),1 );

}

static void test_for_second(void **text){

    assert_int_equal(checkNumberBase("123",5),1 );

}
static void test_for_third(void **text){

    assert_int_equal(checkNumberBase("12Adff233",25),1 );

}

static void test_for_fourth(void **text){

    assert_int_equal(checkNumberBase("12dff233",1),0 );

}

int main()
{
const struct CMUnitTest tests[] =
    {
    cmocka_unit_test(test_for_first),
    cmocka_unit_test(test_for_second),
    cmocka_unit_test(test_for_third),
    cmocka_unit_test(test_for_fourth),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
//return 0;
}
