#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

//#include "stack.h"

// unit-test function

int function(char *string, int syst)
{
int maxSymb = 0;
      char str[] = "123";
      char *buf[100];
        printf("!");

      strcpy(buf,string);
  //char key[] = "aeiou";
  printf("!");
for(int i = 0; i < strlen(&buf); i++)
{
    printf("!");

    for(int j = 0; j < strlen(&str); j++){
              printf("!");

        if((buf[i]==str[i] )&& (j>=maxSymb))
        maxSymb = j;
        }
}
printf("\n%c", str[maxSymb]);
return 0;
}

int main(void) {
    char *string = "123";
    int sys = 5;
    function(string, sys);

}
