#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    int size=10,i;
    int mas[size];
    //��������� �������� ������ ����� ����� ������ N ����������, �� ������� ���������� �� ������.
    for (i = 0; i<size; i++)
    {
        printf("mas[%i] =", i);
        scanf("%i", &mas[i]);
    }

    //������� �������� �������� ������ ����� ���� �� �����.
    for (i = 0; i<size; i++)
    {
        printf("%i,", mas[i]);

    }
    //������ � ������� �� ����� ���� ��� ��'����� ��������.
    int negsum=0;
    for (i = 0; i<size; i++)
    {
        if(mas[i]<0)
        {
            negsum+=mas[i];
        }

    }
    printf("\nnegsum=%i;\n", negsum);

//������ ��'��� �������� ������ � ������� �� �� ���.


    for (i = 0; i<size; i++)
    {
        if(mas[i]<0)
        {
            mas[i]=0;
        }

    }
//������� �� ���hohlomassa��� �������� ������ ����� ���� �� ����� ������.
for (i = 0; i<size; i++)
    {
        if(mas[i]>0)
        {
            printf("%i,", mas[i]);
        }

    }
//������ ������� �������� ������ �������� ���� ��� ��������� �������� ������.
int sum=0,a=0;
for (i = 0; i<size; i++)
    {
        sum=mas[i]+sum;

}
for (i=0; i<size; i++)
    {   a=sum-mas[i];
        mas[i]=sum-mas[i];
        sum=a;

}
printf("\n");

for (i = 0; i<size; i++)
    {

            printf("%i,", mas[i]);


    }
//������ ������� �������� ������ �������� ������ �� �������� � ��������� ��������� ������. �������� ���������� �������� ������ ������� �����.

for (i=0; i<size; i++)
    {
        mas[i]=mas[i]-mas[i+1];


}
mas[size-1]=0;

//������� �������� ���������� ���������� � ���������� ������������� �������� ������.
int max=0,min=0,MAX,MIN;
    for (i=1; i<size; i++)
    {
        if (mas[i]>=mas[max])
            max=i;
    }

for (i=1; i<size; i++)
    {
        if (mas[i]<=mas[min])
            min=i;
    }
MAX=mas[max];
MIN=mas[min];
mas[max]=mas[min];
mas[min]=MAX;

//������� ����� K ��������� �������� ������ � ������� K �������������.

int k=3,g;
do{
     if (mas[i]==MIN)
     {mas[i]=MAX;
     g++;}
     if (mas[i]=MAX)
        {mas[i]=MIN;
        i++;
    }}
while (i+g<k);
printf("\n");

for (i = 0; i<size; i++)
    {

            printf("%i,", mas[i]);


    }
















}

