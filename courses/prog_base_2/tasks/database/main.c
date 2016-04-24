#include <stdio.h>
#include <stdlib.h>

#include "cashier.h"
#include "cashier_module.h"
#define CASHIERS_MAX_COUNT 100
#define FILTER_MAXCASH 350000
#define FILTER_MINMONTHS 1.5
#define DATABASE_PATH "Cashier.data"




int main()
{
    data_t * data = database_new(DATABASE_PATH);
    cashier_t cashierList_filter[CASHIERS_MAX_COUNT];
    int cashiersCount = database_countCashiers(data);
    printf("Cashiers: [%d]", cashiersCount);
    int filterCount = database_filterCashiers(data, FILTER_MAXCASH, FILTER_MINMONTHS, cashierList_filter, cashiersCount);
    printf("Cashiers with \n1)more than [%d] cash;\n2)more than [%.3f] months of work;\n>%d",
           FILTER_MAXCASH, FILTER_MINMONTHS, filterCount);
    printf("\n\n");
    printf("Cashier with this state\n\n");
    cashier_printList(cashierList_filter, filterCount);
    printf("\n\n");
    printf("Cashier #2:\n");
    cashier_t *cashierToCheckId = database_getCashierById(data, 2);
    cashier_print(cashierToCheckId);
	printf("Updating cashier with id 1 (See comments in main).\n");
    cashier_t cashierForUpdateFunc = {2, "Fedor", "Matroskin", 2000, 1.0, "1968-05-11"};
    database_updateCashier(data, &cashierForUpdateFunc, 1);
    printf("\n\n");
    return 0;
}
