#include <stdio.h>

#include "cashier.h"

void cashier_printList(const cashier_t *cashSet, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%i.", (i+1));
        cashier_print(&cashSet[i]);
        printf("\n");
    }
}


void cashier_print(const cashier_t *this)
{
    printf("Surname: %s\n"
           "Surname: %s\n"
           "Cash: %i\n"
           "Months: %.2f\n"
           "Birthdate: %s\n",
           this->name,
           this->surname,
           this->cash,
           this->months,
           this->birthDate);
}

