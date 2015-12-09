#include <stdio.h>
#include <stdlib.h>

int req1(int i, const char sValue[])
{

    if (i==strlen(sValue)){
        return 0;
    }

    int number = (int)sValue[i];
    if (( number>=48) && (number <=57)){
        return number;
    }

    else{
        return req1(i+1, sValue);
    }
}
int req2(int i, const char sValue[])
{
    if (i<0)
        return 0;

    int number = (int)sValue[i];
    if (( number>=48) && (number <=57)){
        return number;
    }

    else{
        return req2(i-1, sValue);
    }
}
int main()
{
    char inStr[10000];
    printf("Enter: ");
    gets(inStr);
    int result = req1(0, inStr) * req2(strlen(inStr)-1, inStr);
    printf("Result: %i", result);
    return 0;
}


