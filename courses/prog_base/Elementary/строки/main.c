#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int i, n=1;
//������� ������, ��� ��� ����������.
char mas[100];
printf("\nput string\n");
scanf("%s",mas);/*
//������� ������ �� ����� N ��� � ������, ����� ������ �� ���������� � ������ �����.

for (i=0;i<n; i++)
{
    puts(mas);
}
// ������� � ������ �� ������� � �������� ������ �� ������� ������� � ��������� ������ � �������. ������� ������ � ������.
for (i=0;i<strlen(mas);i++)
{
    if((mas[i]>='a')&&(mas[i]<='z'))
    {
        mas[i]=toupper(mas[i]);
        continue;
    }


    if((mas[i]>='A')&&(mas[i]<='Z'))
    {
        mas[i]=tolower(mas[i]);
         continue;
    }
}

    puts(mas);
// ���������� � ������� ������� ��� �������� ������� � ������.
int num=0;
for (i=0;i<strlen(mas);i++)
{
if((mas[i]>='0')&&(mas[i]<='9'))
    num++;
}
printf("\nnum=%i",num);
// ������� ���� ��� �������� ������� �� ������.
int sum=0;
for (i=0;i<strlen(mas);i++)
{
if((mas[i]>='0')&&(mas[i]<='9'))
    sum+=mas[i]-'0';
}
printf("\nsum=%i",sum);
// ����������� ������ � ������ ������� N, (N < ������� ������).

int N=5;
for (i=N;i<strlen(mas);i++){
   mas[i]=' ';}
    puts(mas);
// ���������� ������� ������ � ������ ���� ������. ��������� �� �������� ����� �� � ������ � ������� ������.
printf("\nput char\n");
char mat;
_flushall();
mat=getchar();
int c = 0;
for (i=0;i<strlen(mas);i++){
if(mas[i]==mat)
    {printf("YEAH");
    break;
    }
else {
        c++;
}

}
if (c==(strlen(mas)))
    printf("NO!");
*/
// ���������� ������� 2 ������. ��������� �� ������� (�������� �������) ����� ������ � ����� ������ ���� � ���.
char mas2[100];
char *istr;
printf("\nput string2\n");
scanf("%s",mas2);/*
istr = strstr (mas,mas2);
if ( istr == NULL)
printf("NO!");
   else
     printf("YEAH");

    */

 //���������� ������� �������� ����� ������ � �����
 int count=0;
 char *p=&mas;
int a=0;
int d=0;
int axe=0;
int t=1;
/*
do{
if(d==0)
{
    axe=0;
    d++;
}
istr = strstr (mas+axe,mas2);
axe=strlen(mas2);
     if ( istr == NULL)
     {

         break;
     }


        count++;


   }
while (( istr != NULL));
*/
while (t)
{
  if(d==0)
{
    axe=0;
    d++;
}
istr = strstr (mas+axe,mas2);
axe=strlen(mas2);
     if ( istr == NULL)
     {

         t=0;
     }


        count++;


}
  printf("\nCOunt=%d",count);
    return 0;
}
