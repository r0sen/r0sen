#include <stdio.h>
#include <math.h>
#include <time.h>
#include <math.h>
int mat2[4][4];
void fillRand(int mat[4][4])
{
    time_t t;
    srand((unsigned) time(&t));
    int i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            mat[i][j]=rand() % 1999 -999;
        }
}
void rotateCCW90(int mat[4][4])
{
    int i,j,k,r,temp;
    int *p;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            mat2[i][j]=mat[j][3-i];//
        }
}
void flipV(int mat[4][4])
{
    int i,j;
    for (i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            mat2[i][j]=mat[3-i][j];
        }
}
void transposSide(int mat[4][4])
{
    int i,j;
    for (i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            mat2[i][j]=mat[3-j][3-i];
        }
}
