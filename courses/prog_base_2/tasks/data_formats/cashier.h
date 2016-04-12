#include <time.h>

typedef struct cashier_s{
    char name[20];
    char surname[20];
    struct tm birthday;
    float salary;
    int cashboxID;
} cashier_t;

cashier_t* cashier_new();

void cashier_delete(cashier_t* cashier);

void xmlParse(cashier_t* cashierSet[], const char * XMLFileName);

void print_function(cashier_t* cashier);
