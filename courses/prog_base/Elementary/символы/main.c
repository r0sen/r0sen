#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    // ������� ������ �� ����������� � �������� � �����, ������� ��� ������ ����� N ��� ����� � ������.
    int i,N=100;
    char s;

    s=getchar();
    for(i=0;i<N;i++)
    putchar(s);

// ��������� �� ������ � ������ � ������� ��������� (1 - ���, 0 - �).
if((s>='0')&&(s<='9'))
    printf("\n1");else printf("\n0");
    //��������� �� ������ � ������ � ������� ���������.
if(((s>='A')&&(s<='Z'))||((s>='a')&&(s<='z')))
    printf("\n1");else printf("\n0");
    //���� ������ � ��������� ������ ������� 2, ���� � �������� 1, ���� �� ����� - ������� 0.
if((s>='A')&&(s<='Z'))
    printf("\n2");
if((s>='a')&&(s<='z'))
    printf("\n1");
    // ��������� �� � ������ ������ (������������) � ������� ���������.

if(s=' ')
     printf("\n1");
// �������� ��������� ����� ������� � ��������� ���� ���������, �� ������� ����������.
char mas[100];
printf("\nput chars\n");
scanf("%s",mas);

//������� �� ������ ������� � ����� ������� �� ������, ������� �������� ������ ������� ����� ����.
for (i=0;i<100;i++)
{
    if((mas[i]>='0')&&(mas[i]<='9'))
    {
mas[i]=' ';
    }

}
for (i=0;i<strlen(mas);i++)
{
    printf("%c, ",mas[i]);
    }
// � ����� ������� ������� �� ����� � �������� ������ � ������ ������, � �� ������ ������� ������� �� ������� (9 - �����, ���������, ���� ������ '3', �� ������� ���� �� 9 - 3 = '6').

for (i=0;i<strlen(mas);i++)
{
    if ((mas[i]>='0')&&(mas[i]<='9'))
    {
        mas[i]='9'-(mas[i]-'0');
        continue;
    }
    if((mas[i]>='A')&&(mas[i]<='Z'))
    {
        mas[i]=tolower(mas[i]);
        continue;
    }
    if((mas[i]>='a')&&(mas[i]<='z'))
    {
        mas[i]=toupper(mas[i]);
         continue;
    }
}
printf("\n%s",mas);
// ������ ������ ������� ���������� ������� � �����.
for (i=0;i<strlen(mas);i++)
{
    if(((mas[i]>='A')&&(mas[i]<='Z'))||((mas[i]>='a')&&(mas[i]<='z')))
    {
      printf("\nindex = %i",i);
        break;
    }

}
// ������� ������ ������ ��������� � ������ �������� ������ � ����� �������.
char letter, num;
int inst1,inst2;
for (i=0;i<strlen(mas);i++)
{
    if(((mas[i]>='A')&&(mas[i]<='Z'))||((mas[i]>='a')&&(mas[i]<='z')))
    {
      letter=mas[i];
      inst1=i;
        break;
    }}
for (i=0;i<strlen(mas);i++)
{
   if ((mas[i]>='0')&&(mas[i]<='9'))
   {
       num=mas[i];
       inst2=i;
       break;
   }
}
mas[inst1]=num;
mas[inst2]=letter;

printf("\n%s",mas);

// ������� ����� �������. ���������� �� ������� ������� �� ������� ������, ���� �� ������ �������, � � ���� �� ���� �������. ������� ������������ ����� � ������.


int tt1=0,tt2=0,tt3=0;

for (i=1;i<strlen(mas);i++)
{
    if(((mas[i]>='A')&&(mas[i]<='Z'))||((mas[i]>='a')&&(mas[i]<='z')))
    {
        tt1++;
    }
    if ((mas[i]>='0')&&(mas[i]<='9'))
   {
       tt2++;
       }
else
{
    tt3++;
}
}
int j1=0,j2=0,j3=0;
char tmp1[tt1+1],tmp2[tt2+1],tmp3[tt3+1];
tmp1[tt1]='\0';
tmp2[tt2]='\0';
tmp3[tt3]='\0';
for (i=1;i<strlen(mas);i++)
{
    if(((mas[i]>='A')&&(mas[i]<='Z'))||((mas[i]>='a')&&(mas[i]<='z')))
    {
       tmp1[j1]=mas[i];
       j1++;

    }
    if ((mas[i]>='0')&&(mas[i]<='9'))
   {
      tmp2[j2]=mas[i];
      j2++;
       }
  else{
    tmp3[j3]=mas[i];
    j3++;
  }
}
strcpy(mas," ");
strcat(mas,tmp1);
strcat(mas,tmp2);
strcat(mas,tmp3);
// ������� ����� ������� � ������� ������. ��������� �� �������� ���� � ��� ������� ������ � ����� �������
char mas2='o';
int c = 0;
for (i=1;i<strlen(mas);i++){
if(mas[i]==mas2)
    {printf("YEAH");
    break;
    }
c++;

}
if (c==(strlen(mas)-1))
    printf("NO!");
return 0;
}
