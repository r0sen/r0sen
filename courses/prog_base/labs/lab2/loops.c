#include <stdio.h>
#include <math.h>
double calc(int n, int m);
int main()
{
int g;
g=calc(1,1);
return (0);
}
double calc(int n, int m)
{
 int i,j,a=0;
    int c=0;
    int b=0;
    for (i=1; i<=n; i++)
    {
        a=1+i;
        for(j=1; j<=m; j++)
        {
            b=cos((j*(M_PI))/2)+b;
        }
        c=(a*b)+c;

    }

    printf("%i", c);
    return c;
}
