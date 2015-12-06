#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void may_not();
int main()
{    time_t t;
    srand((unsigned) time(&t));
    may_not();
    return (0);
}
