#ifndef TEAHERS_H_INCLUDED
#define TEAHERS_H_INCLUDED


#define BUFFER_LENGTH 100000
#define MSG_LENGTH 10000
#define WORD_LENGTH 100

typedef struct list_s list_t;


typedef struct cashier_s
{
    int Passport;
    char *name;
    char *surname;
    int cash;
    double period;
    char *birthdate;
} cashier_t;

//cashiers_list
cashier_t *new_cashier(void);
void free_cashier(cashier_t *self);

list_t *list_new(void);
int list_add(list_t *base, cashier_t *self);
int list_find(list_t *base, cashier_t *self);
cashier_t *list_get(list_t *base, int index);
cashier_t *list_remove(list_t *base, int index);
void list_free(list_t *self);
int list_count(list_t *self);
int list_find_id(list_t *self, int id);
int list_id(list_t *self, int index);

//xmlproces
char* cashier_to_message(cashier_t *self, int id);
char* all_cashiers_to_message(list_t *list);
char *mine_to_message(void);


#endif // TEAHERS_H_INCLUDED
