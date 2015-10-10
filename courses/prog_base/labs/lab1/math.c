
#include <math.h>


double calc(double x, double y, double z) {
   double a;
   a = (pow(x, y + 1)) / pow(x - y, (1 / z)) + y / 4 * abs(x + y) + pow(abs((cos(y) / sin(x)) + 1), 0.5);
   return a;
}
