#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,l;
    int i,j,k;

    //Користувач вводить два числа N i M, створити матрицю NхM і заповнити її випадковими числами. Вивести її на екран.
    scanf("%i",&n);
    scanf("%i",&m);
    scanf("%i",&l);
    int mas[n][m][l];
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            for(k=0; k<l; k++)
            {
                mas[i][j][k] = 1 + rand() % 9;

            }
        }
    }
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {for(k=0; k<l; k++){
            printf("%i ",mas[i][j][k]);

        }
        printf("\n");}
        printf("\n");
    }

//Знайти суму елементів трьохмірного масиву NхMxL і вивести результат.
int sum=0;
 for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {for(k=0; k<l; k++){
            sum+=mas[i][j][k];
        }}}
printf("sum=%i",sum);
//Знайти суму елементів головної діагоналі трьохмірного куба NхNxN і вивести результат.
int sum1=0;
 for (i = 0,j=0,k=0; i<n,j<m,k<l; i++,j++,k++){

            sum1+=mas[i][j][k];
}
printf("\nsum1=%i",sum1);
//Знайти значення і індекси максимального елемента трьохмірного масиву NхMxL.
 int max1=0,max2=0,max3=0,MAX=0;
 for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {for(k=0; k<l; k++){
            if(mas[i][j][k]>=mas[max1][max2][max3])
            {
                MAX=mas[i][j][k];
                max1=i;
                max2=j;
                max3=k;
            }
        }}}
    printf("\nmas[%i][%i][%i]=%i",max1,max2,max3,MAX);

// Поміняти місцями значення останнього мінімального і останнього максимального елементів трьохмірного масиву NхMxL.
int min1=0,min2=0,min3=0,MIN=0;
for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {for(k=0; k<l; k++){
            if(mas[i][j][k]>=mas[min1][min2][min3])
            {
                MIN=mas[i][j][k];
                min1=i;
                min2=j;
                min3=k;
            }
        }}}

// Поміняти місцями значення останнього мінімального і останнього максимального елементів трьохмірного масиву NхMxL.
mas[min1][min2][min3]=MAX;
mas[max1][max2][max3]=MIN;
    return (0);

}

