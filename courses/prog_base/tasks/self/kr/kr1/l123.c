//Mедведський Денис КП-51
#include <stdio.h>
#include <conio.h>
void main()
{
char num[40];
int i;
printf("enter the number, then press <Enter>");

scanf("%s",&num);
i = 0;
while (num[i] >= '0' && num[i] <= '9')
i++;

printf("Scan number ");
if (num[i]){
printf("not ");}

printf("integer\n");

getch();
}
