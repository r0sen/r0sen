#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n,m,l;
    int i,j,k;

    //���������� ������� ��� ����� N i M, �������� ������� N�M � ��������� �� ����������� �������. ������� �� �� �����.
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







}

