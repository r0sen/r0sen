#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n,m,l,o,p,q;
    int i,j,k,g,f,h;

    scanf("%i",&n);
    scanf("%i",&m);
    scanf("%i",&l);
    scanf("%i",&o);
    scanf("%i",&p);
    scanf("%i",&q);

    int mas[n][m][l][o][p][q];
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            for(k=0; k<l; k++)
            {
                for (g = 0; g<o; g++)
                {
                    for(f=0; f<p; f++)
                    {
                        for(h=0; h<q; h++)
                        {
                            mas[i][j][k][g][f][h] = 1 + rand() % 9;

                        }
                    }
                }
            }
        }
    }

// Вивести суму елементів 6-тимірного масиву цілих чисел.
    int sum=0;
    for (i = 0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            for(k=0; k<l; k++)
            {
                for (g = 0; g<o; g++)
                {
                    for(f=0; f<p; f++)
                    {
                        for(h=0; h<q; h++)
                        {
                            sum+=mas[i][j][k][g][f][h];

                        }
                    }
                }
            }
        }
    }
    printf("sum=%i",sum);

    //Знайти значення і індекси останнього максимального елемента 5-тимірного масиву цілих чисел.
int    mas1[10][10][10][10][10];
    int i1,j1,k1,g1,f1;
    int max1=0,max2=0,max3=0,max4=0,max5=0,MAX;
for (i1 = 0; i1<10; i1++)
    {
        for(j1=0; j1<10; j1++)
        {
            for(k1=0; k1<10; k1++)
            {
                for (g1 = 0; g1<10; g1++)
                {
                    for(f1=0; f1<10; f1++)
                    {
                        mas1[i1][j1][k1][g1][f1]= 1 + rand() % 999;}}}}}

    for (i1 = 0; i1<10; i1++)
    {
        for(j1=0; j1<10; j1++)
        {
            for(k1=0; k1<10; k1++)
            {
                for (g1 = 0; g1<10; g1++)
                {
                    for(f1=0; f1<10; f1++)
                    {
                        if(mas1[i1][j1][k1][g1][f1]>=mas1[max1][max2][max3][max4][max5]){
MAX=mas1[i1][j1][k1][g1][f1];
                        max1=i1;
                        max3=k1;
                        max2=j1;
                        max4=g1;
                        max5=f1;
                    }}
                }
            }
        }
    }
    printf("\nmas1[%i][%i][%i][%i][%i]=%i",max1,max2,max3,max4,max5,MAX);
// Вивести на екран 4-римірний масив цілих чисел у вигляді матриці матриць.

int    mas2[3][3][3][3];
    int i2,j2,k2,g2;
for (i2 = 0; i2<3; i2++)
    {
        for(j2=0; j2<3; j2++)
        {
            for(k2=0; k2<3; k2++)
            {
                for (g2 = 0; g2<3; g2++)
                {

                        mas2[i2][j2][k2][g2]= 1 + rand() % 9;}}}}
for (i2 = 0; i2<3; i2++)
    {
        for(j2=0; j2<3; j2++)
        {
            for(k2=0; k2<3; k2++)
            {
                for (g2 = 0; g2<3; g2++)
                {

                        printf("%i ",mas2[i2][j2][k2][g2]);}printf("\n");}printf("\n");}printf("\n");}




    return 0;
}
