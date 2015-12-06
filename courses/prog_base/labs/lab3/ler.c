#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SCCP SetConsoleCursorPosition(hConsole, pos)
void reset (double arr[],int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        arr[i]=0;
    }
}
void random (double arr[],int size)
{
    int i;
    int x, k, first, last;
    printf("set the left border: ");
    scanf("%i",&first);
    printf("set the rigt border: ");
    scanf("%i",&last);
    if (last==first)
    {

        last++;
    }
    double r;
    for (i=0; i<size; i++)
    {
        x = rand() % (last - first) + first;
        k = rand() % 100;
        r = (double)k/100;
        arr[i] = x + r;
    }
}
void change(double arr[],int size)
{
    int i;
    float a;
    printf("set number of element to change>>");
    scanf("%i",&i);
    printf("set value>>");
    scanf("%fl",&a);
    arr[i]=a;
}
void reverse(double arr[],int size)
{
    int i;
    float temp1 = 0,temp2=0;
    for (i = 0; i<((size/2)-1); i++)
    {
        temp1=arr[i];
        temp2=arr[size-1-i];
        arr[size-1-i]=temp1;
        arr[i]=temp2;
    }
}
void sum(double arr[],int size)
{
    int i;
    double sum=0;
    for (i = 0; i<size; i++)
    {
        sum+=arr[i];
    }
    printf("sum of elements = %.2f\n", sum);
    system("pause");
}
void positive(double arr[],int size)
{
    int i;
    int num=0;
    for (i = 0; i<size; i++)
    {
        if (arr[i]>=0)
            num++;
    }
    printf("the number of positive = %i\n", num);
    system("pause");
}
void shift1(double arr[],int size)
{
    int i,j;
    int n;
    printf("put shift");
    scanf("%i",&n);

    for (i = n,j=0; i<(size+n),j<size; i++,j++)
    {
        if(j<(size-n))
        {
            arr[j]=arr[i];
        }
        else
        {
            arr[j]=0;
        }
    }

}
void help()
{
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = 30;
    pos.Y = 14;
    SCCP;
    printf("ALL COMMANDS:\n");
    printf("Type:\n");
    printf("reset       to reset all elements\n");
    printf("random      to do random\n");
    printf("change      to change element\n");
    printf("reverse     to reverse array\n");
    printf("sum         to sum all elements\n");
    printf("positive    to reset all elements\n");
    printf("shift1      to shift some elements\n");
    printf("shift2      to cyclical shift some elements\n");
    printf("max         to find max\n");
    printf("pow         to pow\n");
    printf("minimax     to change first min with first max\n");
    system("pause");
    system ("cls");
}
void shift2(double arr[],int size)
{
    int i,j;
    printf("put shift: ");
    int a;
    scanf("%i",&a);
    float tmp1;
    for(j= 0; j<a; j++)
    {
        tmp1=arr[0];
        for(i = 1; i<size; i++)
        {
            arr[i-1] = arr[i];
        }
        arr[size-1] = tmp1;
    }
}
void pov(double arr[],int size)
{
    int i;
    int p;
    printf("\nput pow:");
    scanf("%i",&p);
    for(i = 0; i<size; i++)
    {
        arr[i] = pow(arr[i],p);
    }
}
void MAX(double arr[],int size)
{
    int i;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 10;
    pos.Y = 3;
    SCCP;
    int max=0;
    for (i=1; i<size; i++)
    {
        if (arr[i]>=arr[max])
            max=i;
    }
    for (i = 0; i<size; i++)
    {
        if(i!=max)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED| BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
            printf("%.2f",arr[i]);
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
            printf("  ");
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
            printf("%.2f",arr[i]);
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
            printf("  ");
        }
    }
    pos.X = 0;
    pos.Y = 15;
    SCCP;
    system("pause");
}
void minimax(double arr[],int size)
{
    int i;
    int max=0,min=0,MAX1;
    for (i=1; i<size; i++)
    {
        if (arr[i]>arr[max])
            max=i;
    }

    for (i=1; i<size; i++)
    {
        if (arr[i]<arr[min])
            min=i;
    }
    MAX1=arr[max];
    arr[max]=arr[min];
    arr[min]=MAX1;
}
void may_not()
{
    int i,size;
    system("color F0");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12|10);
    char mas[100];
    for(;;)
    {
        printf("Put size of array:\n >> ");
        while( scanf("%i",&size)==0)
        {
            while(!isspace((int)(size=getchar())));
            ungetc(size,stdin);
            printf("Put NUMBER!!!\n >> ");
        }
        system("color F0");
        SetConsoleTextAttribute(hConsole, 12|10);
        break;
    }
    double arr[size];
    system("cls");
    int k;
    double r;
    int x;
    for (i = 0; i<size; i++)
    {
        x=1+(rand() % 100);
        k=1+(rand() % 100);
        r=(double)(k*0.01);
        arr[i]=x+r;
    }
    for(;;)
    {
        system("color F0");
        COORD pos;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        pos.X = 10;
        pos.Y = 3;
        SCCP;
        {
            for (i = 0; i<size; i++)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
                printf("%.2f",arr[i]);
                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
                printf("  ");
            }
        }
        pos.X = 0;
        pos.Y=13;
        SCCP;
        printf("Put a command>>");
        scanf("%s", mas);
        if (strcmp(mas,"reset")==0)
        {
            reset(arr,size);
        }
        if (strcmp(mas,"change")==0)
        {
            change(arr,size);
        }
        if (strcmp(mas,"random")==0)
        {
            random (arr,size);
        }
        if (strcmp(mas,"reverse")==0)
        {
            reverse(arr,size);
        }
        if (strcmp(mas,"sum")==0)
        {
            sum(arr,size);
        }
        if (strcmp(mas,"positive")==0)
        {
            positive(arr,size);
        }
        if (strcmp(mas,"shift1")==0)
        {
            shift1(arr,size);
        }
        if (strcmp(mas,"help")==0)
        {
            help();
        }
        if (strcmp(mas,"shift2")==0)
        {
            shift2(arr,size);
        }
        if (strcmp(mas,"pow")==0)
        {
            pov(arr,size);
        }
        if (strcmp(mas,"max")==0)
        {
            MAX(arr,size);
        }
        if (strcmp(mas,"minimax")==0)
        {
            minimax(arr,size);
        }
        system ("cls");
    }
}
