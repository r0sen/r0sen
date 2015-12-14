#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int i, n=1;
//Зчитати строку, яку ввів користувач.
char mas[100];
printf("\nput string\n");
scanf("%s",mas);/*
//Вивести строку на екран N раз у консолі, кожна строка має виводитись з нового рядка.

for (i=0;i<n; i++)
{
    puts(mas);
}
// Замінити у строці всі символи у нижньому регістрі на відповідні символи у верхньому регістрі і навпаки. Вивести строку у консолі.
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
// Порахувати і вивести кількість всіх цифрових символів у строці.
int num=0;
for (i=0;i<strlen(mas);i++)
{
if((mas[i]>='0')&&(mas[i]<='9'))
    num++;
}
printf("\nnum=%i",num);
// Вивести суму всіх цифрових символів із строки.
int sum=0;
for (i=0;i<strlen(mas);i++)
{
if((mas[i]>='0')&&(mas[i]<='9'))
    sum+=mas[i]-'0';
}
printf("\nsum=%i",sum);
// Перетворити строку і строку розміром N, (N < довжини строки).

int N=5;
for (i=N;i<strlen(mas);i++){
   mas[i]=' ';}
    puts(mas);
// Користувач вводить строку і окремо один символ. Визначити чи міститься такий же ж символ у введеній строці.
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
// Користувач вводить 2 строки. Визначити чи входить (міститься повністю) друга строка у першу строку хоча б раз.
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

 //Порахувати кількість входжень другої строки у першу
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
