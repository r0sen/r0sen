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
    int mas[n][m][k];
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





    return (0);

}

