#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double long2double(long long inputcode)
{
    int i, ex=0;
    int arr[64];
    int znak=arr[0];
    double m=0;

    for (i=63; i>=0; inputcode>>=1, i--){
        arr[i]=inputcode & 1;
    }

    for (i=1; i<=11; i++){
        if (arr[i]==1){
            ex += pow(2, 11-i);
        }
    }

    for (i=12; i<=63; i++){
        if (arr[i]==1){
            m += pow(2, 11 - i);
        }
    }

    if (ex>0 && ex<2047){
        return pow(-1, znak) * pow(2, ex-1023) * (m+1);
    }

    if (ex==0 && m!=0){
        return pow(-1, znak) * pow(2, -1022)*m;
    }

    if (znak==1 && ex==0 && m==0){
        return -0.;
    }

    if (znak==0 && ex==0 && m==0){
        return 0.;
    }

    if (ex==2047 && m!=0){
        return NAN;
    }

    if (znak==1 && ex==2047 && m==0){
        return -INFINITY;
    }

    if (znak==0 && ex==2047 && m==0){
        return INFINITY;
    }
}
