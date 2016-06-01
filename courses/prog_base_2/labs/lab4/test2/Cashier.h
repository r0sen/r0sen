#ifndef FREELANSER_H_INCLUDED
#define FREELANSER_H_INCLUDED

typedef struct Cashier cashca;

cashca * Cashier_new(void);
void Cashier_free(cashca *);
void Cashier_print(cashca *);

void Cashier_set(cashca *, char *, char * , double , char *, int );

char * Cashier_name_get(cashca *);
char * Cashier_surname_get(cashca *);
char * Cashier_date_get(cashca *);
double Cashier_age_get(cashca *);
char * Cashier_companyName_get(cashca *);
int Cashier_salary_get(cashca *);

#endif
