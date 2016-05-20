#include <stdio.h>
#include <stdlib.h>


#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>


#include "roulette.h"


/**
static void subsPlayers_players_equally(void **state){
    roulette_t * myroulette = roulette_new();
        void (*cb1)(const char * message, const char * name, roulette_t * self) = player;
        roulette_subscribe(myroulette, cb1, "Player1");
        void (*cb2)(const char * message, const char * name, roulette_t * self) = player;

        roulette_subscribe(myroulette, cb1, "Player2");

    assert_int_equal(roulette_getSize(myroulette), 2);
    roulette_free(myroulette);
}
static void newRoulette_void_zeroCount(void **state){
    roulette_t * myroulette = roulette_new();
    assert_int_equal(roulette_getStatus(myroulette), ROULETTE_OK);
    roulette_free(myroulette);
}

static void subsPlayers_players_overflow(void **state){
    roulette_t * myroulette = roulette_new();
    int i;
    for(i=0; i<16; i++){
        void (*cb1)(const char * message, const char * name, roulette_t * self) = player;
        roulette_subscribe(myroulette, cb1, "Player");
    }
    assert_int_equal(roulette_getStatus(myroulette), ROULETTE_OVERFLOW);
    roulette_free(myroulette);
}

static void roulette_combinations_status_empty(void **state){
    roulette_t * myroulette = roulette_new();
   roulette_combinations(myroulette);
    assert_int_equal(roulette_getStatus(myroulette), ROULETTE_EMPTY);
    roulette_free(myroulette);
}

static void roulettenew_status_ok(void **state){
    roulette_t * myroulette = roulette_new();
    assert_int_equal(roulette_getStatus(myroulette), ROULETTE_OK);
    roulette_free(myroulette);
}


int main(){
    const struct CMUnitTest unitTests[] =
    {
        cmocka_unit_test(newRoulette_void_zeroCount),
        cmocka_unit_test(subsPlayers_players_overflow),
        cmocka_unit_test(subsPlayers_players_equally),
        cmocka_unit_test(roulette_combinations_status_empty),
        cmocka_unit_test(roulettenew_status_ok)

    };
    return cmocka_run_group_tests(unitTests, NULL, NULL);
}

**/
int main(){
    srand(time(NULL));
    printf("Type something to play\n\n");

    while(1){
        getch();
        roulette_t * myroulette = roulette_new();

        //player_new(myroulette, "Player");
        //administrator_new(myroulette, "Vadim");
        //press_new(myroulette, "Times");

        void (*cb1)(const char * message, const char * name) = press;
        roulette_subscribe(myroulette, cb1, "Times");
        void (*cb2)(const char * message, const char * name) = administrator;
        roulette_subscribe(myroulette, cb2, "Andrey");
        void (*cb3)(const char * message, const char * name) = player;
        roulette_subscribe(myroulette, cb3, "Denis");

        roulette_combinations(myroulette);

        roulette_output(myroulette);
/*
        roulette_combinations(myroulette);
        roulette_output(myroulette);
        roulette_combinations(myroulette);
        roulette_output(myroulette);
        roulette_combinations(myroulette);
        roulette_output(myroulette);
        roulette_combinations(myroulette);
        roulette_output(myroulette);
*/

        roulette_free(myroulette);
    }

    return 0;
}


