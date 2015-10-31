#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(double, double, double);

int main() {
    double xval = 1, yval = -234, zval = 4;
    double result;

    result = calc(xval, yval, zval);

    printf("%.12f", result);
    return 0;
}
double calc(double x, double y, double z) {
   double a, a0, a1, a2;
   if ((x-y==0) || (z==0))
    return NAN;
   if ((x-y!=0) && (z!=0))
     a0 = (pow(x, y + 1)) / pow(x - y, (1 / z));

   if ((x+y==0))
    return(NAN);
   if ((x+y!=0))
    a1= y / 4 * abs(x + y);
   if (sin(x)==0)
     return (NAN);
   if (sin(x)!=0)
        a2 = pow(abs((cos(y) / sin(x)) + 1), 0.5);
    a = a0 +a1 +a2;
   return a;
}
