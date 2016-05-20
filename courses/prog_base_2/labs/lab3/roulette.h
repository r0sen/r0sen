#ifndef ROULETTE_H_INCLUDED
#define ROULETTE_H_INCLUDED
#define MAX_NAME 228
#define MAX_SUBSCRIBERS 15

typedef struct roulette_s roulette_t;

typedef enum event{WIN, HALF_WIN, LOSE,JACKPOT} event;
typedef void (*CallbackFunction)(event, const char *);
typedef enum roulette_status{
	ROULETTE_0,
    ROULETTE_2,
    ROULETTE_3,
    ROULETTE_777,
    ROULETTE_OK,
    ROULETTE_EMPTY,
    ROULETTE_OVERFLOW

} roulette_status_t;

roulette_t * roulette_new();
void roulette_free(roulette_t * self);
void roulette_combinations(roulette_t * self);
void press(event ev, const char * name);
void player(event ev, const char * name);
void administrator(event ev, const char * name);
roulette_status_t roulette_getStatus(roulette_t *);
int roulette_getSize(roulette_t * self);
void roulette_output(roulette_t *self);
#endif // ROULETTE_H_INCLUDED
