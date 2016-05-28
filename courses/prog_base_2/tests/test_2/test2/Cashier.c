#include <stdlib.h>
#include <string.h>

#include "Cashier.h"


struct Cashier {
    char * name;
    char * surname;
    double age;
    char * date;
    int salary;
};

cashca * Cashier_new(void) {
    cashca * newLanc=malloc(sizeof(struct Cashier));
    newLanc->name=NULL;
    newLanc->surname=NULL;
    newLanc->age=0;
    newLanc->date=NULL;
    newLanc->salary=0;
    return newLanc;
}

void Cashier_free(cashca * self) {
    free(self);
}

void Cashier_set(cashca * self, char * name, char * surname, double age, char * date,int salary){
    if(name!=NULL)
    {
    self->name=malloc(sizeof(name));
    strcpy(self->name,name);
    }
    else
        self->name=name;
    if(surname!=NULL)
    {
    self->surname=malloc(sizeof(surname));
    strcpy(self->surname,surname);
    }
    else
        self->surname=surname;
    if(date!=NULL)
    {
    self->date=malloc(sizeof(date));
    strcpy(self->date,date);
    }
    else
       self->date=date;


    self->age=age;

    self->salary=salary;
}


char * Cashier_name_get(cashca * lancer)
{
    return lancer->name;
}

char * Cashier_surname_get(cashca * lancer)
{
    return lancer->surname;
}

char * Cashier_date_get(cashca * lancer)
{
    return lancer->date;
}

double Cashier_age_get(cashca * lancer)
{

    double age=lancer->age;
    return age;
}

int Cashier_salary_get(cashca * lancer)
{
    return lancer->salary;
}
