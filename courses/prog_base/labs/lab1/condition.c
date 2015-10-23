#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int satisfies(int, int, int);

int main() {
   int aval = 0, bval = 4, cval = 4;
   int resultVal;

   resultVal = satisfies(aval, bval, cval);

   printf("%i", resultVal);
   return 0;
}
// copy the code below to the answers files and add #include <math.h> at the beginning
int satisfies(int a, int b, int c)
{
    int signed result, modmin, max, min, sum2;


    if (a<0 && b<0 && c<0)
    {
        modmin == abs(fmin(fmin(a,b),c));}
                     if (fmin(fmin(a,b),c)==a)
    {
        sum2 = b+c;
    }
    if (fmin(fmin(a,b),c)==b)
    {
        sum2 = a+c;
    }
    if (fmin(fmin(a,b),c)==c)
    {
        sum2 = b+a;
    }
    if ( (sum2 <=-256) & (modmin > 0) && ((a &(a - 1)) == 0))
    {
        result = 1;
    }
    else if (abs(sum2)-modmin <16||abs(sum2)<16)
    {
        result = 1;
    }

if ((a<0,b>0,c>0) || (b<0,c>0,a>0) ||(c<0,a>0,b>0))
    {
        if (a<0)
        {
            if (a>-256)
            {
                result = 1;
            }
        };
        if (b<0)
        {
            if (b>-256)
            {
                result = 1;
            }
        };
        if (c<0)
        {
            if (c>-256)
            {
                result = 1;
            }
        };
        if (a<0 & b<0 || a<0 & c<0 || c <0 & b<0)
        {
            if (a<0 & b<0)
            {
                if ((a+b)*4>-256)
                {
                    result = 1;
                }
            }
            if (b<0 & c<0)
            {
                if ((b+c)*4>-256)
                {
                    result = 1;
                }
            }
            if (a<0 & c<0)
            {
                if ((a+c)*4>-256)
                {
                    result = 1;
                }
            }
        }
        if ((a>=0) && (b>=0) && (c>=0))
        {
            max = fmax(fmax(a,b),c);
            min = fmin(fmin(a,b),c);
            if (max%min == 0 && max!=0)
            {
                result = 1;
            }
            if (min == 0)
            {
                result = 0;
            }
            if (max == 0 && min!=0)
            {
                result = 1;
            }
        }
    }



        return result;
}
