#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    int i,j;

    //Користувач вводить два числа N i M, створити матрицю NхM і заповнити її випадковими числами. Вивести її на екран.
    scanf("%i",&n);
    scanf("%i",&m);
    int mas[n][m];
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            mas[i][j] = 1 + rand() % 99;

        }
    }
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%i ",mas[i][j]);

        }
        printf("\n");
    }
    //Задана матриця NхM заповнена випадковими цілими числами. Знайти і вивести суму всіх елементів.
    int sum=0;
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sum+=mas[i][j];
        }
    }


//Матриця NхM. Вивести суми всіх елементів рядків матриці. Вивести суми всіх елементів стовпців матриці.

    int sumarr=0;
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sumarr+=mas[i][j];
        }
        printf("sumarr%i = %i;\n",i,sumarr);
    }
int sumcolumn=0;
    for (j = 0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            sumcolumn+=mas[i][j];
        }
        printf("sumcolumn%i = %i;\n",j,sumcolumn);
    }

//Квадратна матриця NхN. Вивести суму головної і окремо побічної діагоналі.
int sum1=0;
int sum2=0;
for (j = 0,i=0; i<n,j<m; i++,j++)
    {
        sum1+=mas[i][j];
    }
for (i=0,j=(m-1); i<n,j>=0; i++,j--)
    {
        sum2+=mas[i][j];
    }
printf("sum1 = %i;\n",sum1);
printf("sum2 = %i;\n",sum2);

//Квадратна матриця NхN. Вивести суму елементів під головною діагоналлю (не враховуючи елементи діагоналі).
int sumDOWN=0;
 for (j = 0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {   if(j<i)
            sumDOWN+=mas[i][j];
        }
    }
printf("sumDOWN = %i;\n",sumDOWN);

//Знайти і вивести у матриці NхM максимальний елемент.

int max1=0,max2=0;
    for (i=0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
        if (mas[i][j]>mas[max1][max2])
            {max1=i;
            max2=j;}
    }
    }
  printf("MAX = %i;\n",mas[max1][max2]);
  //Знайти і вивести індекси і значення мінімального елемента матриці NхM.

int min1=0,min2=0;
    for (i=0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
        if (mas[i][j]<mas[min1][min2])
            {min1=i;
            min2=j;}
    }
    }
  printf("MIN-->>mas[%i][%i] = %i;\n",min1,min2,mas[min1][min2]);











































    return (0);

}

