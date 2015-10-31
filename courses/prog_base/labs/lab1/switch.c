#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int exec(int op, int a, int b);
int main()
{
    int opval =6 , aval = 15, bval =7 ;
    int resultVal;

    resultVal = exec(opval, aval, bval);

    printf("%i", resultVal);
    return 0;
}

int exec(int op, int a, int b)
{
     int c, result, data_type;
     if (op < 0)
    {
        c = a;
        a = b;
        b = c;
        op = abs(op);
    }
     switch (op)
    {
    case 0:
        result = -a;
        break;
    case 1:
        result = a + b;
        break;
    case 2:
        result = a - b;
        break;
    case 3:
        result = a * b;
        break;
    case 4:
        result = a / b;
        break;
    case 5:
        result = abs(a);
        break;
    case 6:
        result = pow(a, b);
        break;
    case 7:
        result = a % b;
        break;
    case 13:
        result = a % b;
        break;
    case 77:
        result = a % b;
        break;
    case 8:
        if (a>=b){result=a;}else{result=b;};
        break;
    case 9:
        if (a<=b){result=a;}else{result=b;};
        break;
    case 10:
        switch(abs(b)%8)
        {
        case 0:
            data_type = sizeof(char);
            break;
        case 1:
            data_type = sizeof(signed char);
            break;
        case 2:
            data_type = sizeof(short);
            break;
        case 3:
            data_type = sizeof(unsigned int);
            break;
        case 4:
            data_type = sizeof(long);
            break;
        case 5:
            data_type = sizeof(unsigned long long);
            break;
        case 6:
            data_type = sizeof(float);
            break;
        case 7:
            data_type = sizeof(double);
            break;
            }
            result = abs(a) * data_type;
        break;
        case 11:
        result =3.141592*((a + b) % 6)/b;
        break;
        default:
             {
        if (op < 100)
        {
            result =(op % abs(a + 1)) + (op % abs(b + 1));
        }
        else
        {
                result = -1;
        }
    }
    }
    return result;
}
