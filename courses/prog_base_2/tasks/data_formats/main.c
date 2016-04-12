#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <libxml/tree.h>

#include "cashier.h"

int main()
{
	const char * filePath = "cashiers.xml";


    cashier_t * cashier[3];

	int i;
    for(i = 0; i < 3; i++){
        cashier[i] = cashier_new();
    }

    xmlParse(cashier, filePath);

    for(i = 0; i < 3; i++){
        printf("cashier #%i\n", (i+1));
        print_function(cashier[i]);
    }

    for(i = 0; i < 3; i++){
        cashier_delete(cashier[i]);
    }

    return 0;
}
