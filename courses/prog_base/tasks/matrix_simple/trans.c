#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRand(int mat[4][4])
{
    int i, j, num;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            mat[i][j] = rand()%1999 - 999;
        }
    }
}

void rotateCCW90(int mat[4][4])
{
    int matrix2[4][4];
    int i,j,Y;

    for (Y = 0; Y<4; Y++)
    {
        for (i=0, j=3; i<4, j>=0; i++, j--)
        {
            matrix2[j][Y] = mat[Y][i];
        }
    }
    for (i = 0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            mat[i][j] = matrix2[i][j];
        }
    }
}

void flipV(int mat[4][4])
{
    int matrix2[4][4];
    int i,j,Y;
    for (Y = 0; Y<4; Y++)
    {
        for (i=0, j=3; i<4, j>=0; i++, j--)
        {
            matrix2[i][Y] = mat[j][Y];
        }
    }

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            mat[i][j] = matrix2[i][j];
        }
    }
}

void transposSide(int mat[4][4])
{
    int matrix2[4][4];
    int i,j;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4;j++)
        {
            matrix2[3-j][3-i] = mat[i][j];
        }
    }
    for (i=0; i<4; i++)
    {
        for (j=0; j<4;j++)
        {
            mat[i][j] = matrix2[i][j];
        }
    }
}
