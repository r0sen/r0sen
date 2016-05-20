#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roulette.h"

void roulette_subscribe(roulette_t * self, CallbackFunction callback, const char *);

struct roulette_s{
    int num1;
    int num2;
    int num3;
    int size;
    roulette_status_t status;
    CallbackFunction cb[MAX_SUBSCRIBERS];
    char names[MAX_NAME][MAX_SUBSCRIBERS];

};

roulette_t * roulette_new(){
    roulette_t * self = malloc(sizeof(struct roulette_s));
    self->num1 = 0;
    self->num2 = 0;
    self->num3 = 0;
    self->size = 0;
    self->status = ROULETTE_OK;
    return self;
}

void roulette_free(roulette_t * self){
    free(self);
}
void roulette_combinations(roulette_t * self){
    if (self->size == 0){
        self->status = ROULETTE_EMPTY;
        return;
    }
        self->num1 = rand() % 9 + 1;
        self->num2 = rand() % 9 + 1;
        self->num3 = rand() % 9 + 1;



    int i;

    if (self->num1==self->num2&&self->num1==self->num3){
        self->status = ROULETTE_3;
        for (i=0; i<self->size; i++){
            self->cb[i](WIN, self->names[i]);
        }
        return;
    }

    if (self->num1==7&&self->num2==7&&self->num3==7){
        self->status = ROULETTE_777;
        for (i=0; i<self->size; i++){
            self->cb[i](JACKPOT, self->names[i]);
        }
        return;
    }
    if (self->num1==self->num2||self->num2==self->num3||self->num1==self->num3){
        self->status = ROULETTE_2;
        for (i=0; i<self->size; i++){
            self->cb[i](HALF_WIN, self->names[i]);
        }
        return;
    }
    else {
        self->status = ROULETTE_0;
        for (i=0; i<self->size; i++){
            self->cb[i](LOSE, self->names[i]);
        }
    }
    return;
}
void player(event ev, const char * name){

	if (ev==WIN){
        printf("%s U WIN! LEL ! WIN! >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     \n" , name);
        return;
    }
    if (ev==JACKPOT){
        printf("%s U LUCKY! JACKPOT!!! 777 777 777 777 777 777 777 777 777 777 777 777 777    \n" , name);
        return;
    }
    if (ev==LOSE){
        printf("%s Try again ! U lose !\n" , name);
        return;
    }
    if (ev==HALF_WIN){
        printf("%s U have 2 of 3 nums the same :)\n" , name);
        return;
    }

}

void administrator(event ev, const char * name){
    if (ev==JACKPOT){
        printf("Administrator %s informed. Wait please!!!\n", name);
        return;
    }
    else {
        return;
    }
}

void press(event ev, const char * name){
    if (ev==JACKPOT){
        printf("'%s' informed. Paparazzi on the road!!!\n", name);
        return;
    }
    else {
        return;
    }
}


void roulette_subscribe(roulette_t * self, CallbackFunction callback, const char * name){
    if (self->size==MAX_SUBSCRIBERS){
        self->status = ROULETTE_OVERFLOW;
        return;
    }

    self->cb[self->size] = callback;
    strcpy(self->names[self->size], name);
    self->size++;
}

void roulette_output(roulette_t *self){
    printf("%i   %i   %i\n\n", self->num1, self->num2, self->num3);

}

roulette_status_t roulette_getStatus(roulette_t * self){
    return self->status;
}

int roulette_getSize(roulette_t * self){
    return self->size;
}
