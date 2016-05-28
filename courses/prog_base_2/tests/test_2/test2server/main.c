#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"

int main(void){
    list_t *cashiers = list_new();
    http_request_startServer(cashiers);
    list_free(cashiers);
    return 0;
}
