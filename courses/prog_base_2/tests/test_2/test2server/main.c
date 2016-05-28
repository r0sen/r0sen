#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"
#include "http.h"

int main(void){
    list_t *cashiers = list_new();
    startServer(cashiers);
    list_free(cashiers);
    return 0;
}
