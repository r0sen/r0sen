#include <stdio.h>
#include <stdlib.h>

void main()
{

//�������� ������������ ����� � �������� ������ � �������� ����. ������ �������� ����� �� ������. ������� ���� �� �������.
int var;
int* adr;
printf("put int var>>");
scanf("%i",&var);
printf("int var=%i\n",var);
//������� �������� �� �����. ������ ���� ������������ �������� � ����� �������� �������� ���� ������, �� ��� �� �����.

adr=&var;
printf("put int var>>\n");
scanf("%i",adr);
//������� �������� �����.
printf("int var=%i\n",var);
//�������� ������������ ����� � ��� ���������, ��� ������� �� ���� �����. ������ �������� ����� ����� ������ ��������.
int var1;
int* p1=&var1;
int* p2;
p2=&var1;
printf("put int var1>>");
scanf("%i",p1);
//������� �������� ����� ����� ������ ��������.
printf("\nint var1=%i",*p2);
//�������� � ��������� ����� ����� �����. �������� �������� � ������� ���� �� ������ ������� ������. ������� �������� �������� ������ �� ����� �� �������������� ������ ������ �� �������� (����� []), � �� ��������� �������������� ��������� �� �������� �������� ������ � ������ �������� ������ �� ��� ����� ��������.

int mas[10]={0,1,2,3,4,5,6,7,8,9};
int *p3;
p3=mas;
int i;
printf("\n");
while(p3!=mas+10)
    {printf("%i, ",*p3);
    p3++;}
//�������� � ��������� ����� ����� �����. �������� �������� � ������� ���� �� �������� ������� ������. ������� �������� �������� ������ �� ����� �� �������������� ������ ������ �� ��������, � �� ��������� �������������� ��������� �� ����������������� ������ � ������ �������� ������ �� ��� ����� ��������. (����� ���������� �������)
int mas4[10]={0,1,2,3,4,5,6,7,8,9};
int *p4;
p4=mas4+9;

printf("\n");
do
    {printf("%i, ",*p4);
    p4--;}
while(p4!=mas4-1);
//������� ����� ����� ����� � �������� �� ������� ����� ������. ������� �� ��'���� �������� ������ �������������� ����� ��������.
int mas5[10]={0,-1,2,3,4,-5,6,7,-8,9};
int *p5;
p5=mas5;
printf("\n");
while(p5!=mas5+10)
    {
        if(*p5<0)
        printf("%i, ",*p5);
    p5++;}
//������� ����� �������� ����� (������� �������)  � ��� ���������. ������ ����� �� ������ ������� ������, ������ �� �������� ������� ������. �������� ������ �������� �� �������� ��������, ������ �� ��������� ���� ��������� �� ������ ��������� �� ���� � ��� �� �������. ������ �������� � ������� ��������� ������ ��������, �� ��� ����� ������ �������� �� �������� �� ���� ����� ������ ��������.
double mas6[9]={0.0,-1.25,2.56,3.67,4.89,-5.34,6.12,7.546,-8.876};
int *p61,*p62;
p61=mas6;
p62=mas6+9;
printf("\n");
double d;
while(p61!=p62)
    {
d=(double)*p61/ (*p62);
        printf("%f, ",d);
    p61++;
    p62--;}

//������� ����� ������� � �������� �� ���� ������ �������. ������� ������� ������ �� ����� �� ��������� ���� ���������.
char charz[]={'d','e','f','a','u','l','t'};
char *pes=charz;
printf("\n");

while(pes!=charz+7)
{
    printf("%c",*pes);
    pes++;
}
//� ����� ������� ������ ������ ������ ������� (����� �������� �� ������� ������) � ������� �������� �������� �� ������ '\0'. ������� ����� �� ������ � �������.
char charz1[]={'d','e',' ','a','u','l','t'};
char *pes1=charz1;
printf("\n");

while(pes1!=charz1+7)
{
    if(*pes1==' ')
    {*pes1='\0';
    puts(charz1);

    break;
    }
    pes1++;
}
























































}
