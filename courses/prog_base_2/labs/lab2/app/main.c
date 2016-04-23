#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "list.h"

typedef int (*checkFor)(list_t * list);
typedef void (*action)(int check);

const char * dllChoice();
void printList(list_t * list);

list_t * fillRandom(list_t * list)
{
    while(list_callSize(list) < MAX_SIZE)
    {
        list_add(list, rand() % 256 -127);
        printList(list);
    }

}

void printList(list_t * list)
{
    system("cls");
    list_output(list);
}

const char * dllChoice()
{
    int choiseDll = 0;
    while(choiseDll != 1 && choiseDll != 2)
    {
        printf("Please choice num of DLL:\n>> ");
        scanf("%i", &choiseDll);
        if(choiseDll == 1)
            return ("dynLIb.dll");
        else if (choiseDll == 2)
            return ("dynLIb2.dll");
    }
    return NULL;
}

void dllTesting (list_t * list, const char * dllTitle )
{
    HANDLE hLib = LoadLibrary(dllTitle);
    checkFor check = (checkFor)GetProcAddress(hLib, "check_list");
    action act = (action)GetProcAddress(hLib, "action_whenChecked");
    fillRandom(list);
    printList(list);
    act(check(list));
    FreeLibrary(hLib);
}

int main(void)
{
    srand(time(NULL));
    list_t * list = list_newList();
    const char * dllTitle = dllChoice();
    dllTesting(list, dllTitle);
    list_freeList(list);
    return 0;
}


