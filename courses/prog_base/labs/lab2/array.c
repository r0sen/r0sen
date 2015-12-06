#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void fillRand1(int arr[], int size)
{
    int i;
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i<size; i++)
    {
        arr[i] = 1 + rand() % 99;
         printf("arr[%i] = %i;\n", i, arr[i]);
    }
}

int checkRand1(int arr[], int size)
{
    int answer = 1;
    int i;

    for (i = 0; i<size; i++)
    {
        if ((arr[i]<1) || (arr[i]>99)){
            answer = 0;
            break;
            }
    }
    return answer;
}

float meanValue(int arr[], int size)
{
    float average=0;
    int i;
    for (i=0; i<size; i++)
    {
        average+= arr[i];
    }
    average/=size;
    return average;
}
int maxValue(int arr[], int size)
{
    int max=0,i;
    for (i=1; i<size; i++)
    {
        if (arr[i]>arr[max])
            max=i;
    }
    return(arr[max]);
}


int meanIndex(int arr[], int size)
{
int i,min=0;
int answer=0;
float mv = (meanValue(arr,size));
min = 0;

for(i=1; i<size; i++)
{
if(abs(mv-arr[i])<abs(mv-arr[min]))
{
min=i;
}
}
return min;
}

int maxIndex (int arr[], int size)
{
    int max = maxValue(arr, size);
    int stop = 0;
    int answer;
    int i=0;
    while (stop==0)
    {
        if (max ==arr[i])
        {
            stop = 1;
            answer = i;
        }
        i++;
    }
}
int maxOccurance(int arr[], int size)
{
    int i;
    int num[size];
    for (i=0; i<size; i++)
    {
        num[i]=0;
    }
    int j;
    for (i=0; i< size; i++)
    {
        for (j=0; j< size; j++)
        {
            if (arr[i] == arr[j])
                num[i]++;
        }
    }
    int top = num[0];
    int answer = arr[0];
    for (i=0; i< size; i++)
    {
        if ((top < num[i]) || ((top == num[i]) && (answer < arr[i])))
        {
            top = num[i];
            answer = arr[i];
        }
    }
    return answer;
}

int diff(int arr1[], int arr2[], int res[],int meanIndex, int arr[], int size)
{
    int value = 0;

    int i;

    for (i=1; i<size; i++)
    {
        if (arr1[i]-arr2[i]==0)
        {
            res[i]=0;
            value++;
        }
        else
        {
            res[i]=arr1[i]-arr2[i];
        }

    }
if (value=size)
            {return 0;
            }
        return 0;
}


void divv(int arr1[], int arr2[], int res[], int size)
{
    int i;
    for (i = 0; i<size; i++)
    {
        res[i] = arr1[i]/arr2[i];
    }
}

int lteq(int arr1[], int arr2[], int size)
{
    int i;
    for (i = 0; i<size; i++)
    {
        if (arr1[i] <= arr2[i])
            return 0;
    }
    return 1;
}

void lor(int arr1[], int arr2[], int res[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        res[i] = arr1[i] | arr2[i];
    }
}

void main ()
{
    int arr[10];
    int size = 10;
    fillRand1(arr,size);
    int c=checkRand1(arr,size);
    float g = meanValue(arr,size);
    int v= maxValue(arr, size);
    int l=meanIndex(arr, size);
    int k=maxIndex(arr,size);
    printf("checkRand1 = %i\nmeanValue = %f\nmaxValue=%i\nmeanIndex=%i\nmaxIndex=%i\n", c,g,v,l,k);

}
