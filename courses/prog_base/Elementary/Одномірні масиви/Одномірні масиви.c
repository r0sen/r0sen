#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    int size=10,i;
    int mas[size];
    //Заповнити елементи масиву цілих чисел розміру N значеннями, що вводить користувач із консолі.
    for (i = 0; i<size; i++)
    {
        printf("mas[%i] =", i);
        scanf("%i", &mas[i]);
    }

    //Вивести значення елементів масиву через кому на екран.
    for (i = 0; i<size; i++)
    {
        printf("%i,", mas[i]);

    }
    //Знайти і вивести на екран суму всіх від'ємних елементів.
    int negsum=0;
    for (i = 0; i<size; i++)
    {
        if(mas[i]<0)
        {
            negsum+=mas[i];
        }

    }
    printf("\nnegsum=%i;\n", negsum);

//Знайти від'ємні елементи масиву і замінити їх на нулі.


    for (i = 0; i<size; i++)
    {
        if(mas[i]<0)
        {
            mas[i]=0;
        }

    }
//Вивести всі додhohlomassaатні елементи масиву через кому на екран консолі.
for (i = 0; i<size; i++)
    {
        if(mas[i]>0)
        {
            printf("%i,", mas[i]);
        }

    }
//Замість кожного елементу масиву записати суму всіх наступних елементів масиву.
int sum=0,a=0;
for (i = 0; i<size; i++)
    {
        sum=mas[i]+sum;

}
for (i=0; i<size; i++)
    {   a=sum-mas[i];
        mas[i]=sum-mas[i];
        sum=a;

}
printf("\n");

for (i = 0; i<size; i++)
    {

            printf("%i,", mas[i]);


    }
//Замість кожного елементу масиву записати різницю між поточним і наступним елементом масиву. Значення останнього елементу масиву зробити нулем.

for (i=0; i<size; i++)
    {
        mas[i]=mas[i]-mas[i+1];


}
mas[size-1]=0;

//Поміняти значення останнього мінімального і останнього максимального елементів місцями.
int max=0,min=0,MAX,MIN;
    for (i=1; i<size; i++)
    {
        if (mas[i]>=mas[max])
            max=i;
    }

for (i=1; i<size; i++)
    {
        if (mas[i]<=mas[min])
            min=i;
    }
MAX=mas[max];
MIN=mas[min];
mas[max]=mas[min];
mas[min]=MAX;

//Поміняти перші K мінімальних елементів масиву з першими K максимальними.

int k=3,g;
do{
     if (mas[i]==MIN)
     {mas[i]=MAX;
     g++;}
     if (mas[i]=MAX)
        {mas[i]=MIN;
        i++;
    }}
while (i+g<k);
printf("\n");

for (i = 0; i<size; i++)
    {

            printf("%i,", mas[i]);


    }
















}

