#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
struct student
{

    char name[100];
    char Class[10];
    int mathMark;
    int physicsMark;
    int opMark;

};

void readFile(int n, struct student Student[n])
{
    int i;
    FILE *input = fopen("students.txt", "r");
    char line[100];
    fgets(line, 100, input);
    n = line[0] - '0';
    /*if (strlen(line) ==2)
    {
        n= n*10 +line[1] - '0';
    }*/
    //


    for (i=0; i<n; i++)
    {
        fgets(line, 100, input);
        strcpy(Student[i].name, line);

        fgets(line, 100, input);
        strcpy(Student[i].Class, line);
        fgets(line, 100, input);
        Student[i].mathMark = line[0] - '0';

        fgets(line, 100, input);
        Student[i].physicsMark = line[0] - '0';

        fgets(line, 100, input);
        Student[i].opMark = line[0] - '0';
    }
    fclose(input);
}
int getN()
{
    FILE *input = fopen("students.txt", "r");
    char line[100];
    int n,i;
    int length;
    fgets(line, 100, input);
    length=strlen(line);
    for(i=strlen(line)-1;i>=0;i--)
    {
        n+=line[i]*pow(10,strlen(line)-i-1);
    }
    n = line[0] - '0';
    fclose(input);
    return n;
}
void saveFile(int n, struct student Student[n])
{
    FILE *output = fopen("students.txt", "w");
    char line[100];
    int i;
    fprintf(output, "%i\n", n);
    for (i=0; i<n; i++)
    {
        if (Student[i].name[ strlen(Student[i].name) - 1 ]=='\n')
            fprintf(output, "%s", Student[i].name);
        else
            fprintf(output, "%s\n", Student[i].name);

        if (Student[i].Class[ strlen(Student[i].Class)-1 ]=='\n')
            fprintf(output, "%s", Student[i].Class);
        else
            fprintf(output, "%s\n", Student[i].Class);

        fprintf(output, "%i\n", Student[i].mathMark);
        fprintf(output, "%i\n", Student[i].physicsMark);
        fprintf(output, "%i\n", Student[i].opMark);
    }
    fclose(output);
}

void showList()
{
    system("cls");
    int n = getN();
    struct student Student[n];
    readFile(n, Student);
    int rating;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(handle, pos);
    printf("List:");
    int i;
    pos.X = 1;
    pos.Y = 2;
    SetConsoleCursorPosition(handle, pos);
    for (i = 0; i< n; i++)
    {
        rating = (Student[i].mathMark + Student[i].opMark + Student[i].physicsMark)/3;
        printf("%i) %s", i+1, Student[i].name);
        printf("Class: %s", Student[i].Class);
        printf("Math: %i. Physics: %i. OP: %i. ---->", Student[i].mathMark, Student[i].physicsMark, Student[i].opMark);
        if ((Student[i].mathMark!=2) && (Student[i].physicsMark!=2) && (Student[i].opMark!=2))
        {
            if (rating==5)
            {
                SetConsoleTextAttribute(handle, 250);
                printf("has bigger scholarship");
                SetConsoleTextAttribute(handle, 240);
            }

            else if (rating==4)
                {
                    SetConsoleTextAttribute(handle, 249);
                    printf("has normal scholarship");
                    SetConsoleTextAttribute(handle, 240);
                }
            else if (rating==3)
                {
                    SetConsoleTextAttribute(handle, 253);
                    printf("has no scholarship");
                    SetConsoleTextAttribute(handle, 240);
                }
            else
                {
                    SetConsoleTextAttribute(handle, 244);
                    printf("won't continue education");
                     SetConsoleTextAttribute(handle, 240);
                }
        }
        else
            printf("won't continue education");
        printf("\n");

    }
    printf("\n");
    system("pause");
}
void editPlace()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 30;
    pos.Y = 24;
    SetConsoleCursorPosition(handle, pos);
    printf("Enter: ");
}
void changeCurentStudent(struct student *s)
{
    int done =0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
    while(done==0)
    {
        system("cls");

        pos.X = 0;
        pos.Y = 0;
        SetConsoleCursorPosition(handle, pos);
        printf("Name: %s", s->name);
        pos.X = 0;
        pos.Y = 1;
        SetConsoleCursorPosition(handle, pos);
        printf("Class: %s", s->Class);
        pos.X = 0;
        pos.Y = 2;
        SetConsoleCursorPosition(handle, pos);
        printf("Math mark: %i\n", s->mathMark);
        printf("Physics mark: %i\n", s->physicsMark);
        printf("OP mark: %i\n", s->opMark);
        pos.X = 10;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        printf("Enter EditPart: name, class, math, physics, op. Or print exit");
        editPlace();
        char line[10];
        gets(line);
        if (strcmp(line, "name")==0)
        {
            done = 1;
            system("cls");
            pos.X = 20;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("New name: ");
            gets(line);
            strcpy(s->name, line);
        }
        else if (strcmp(line, "class")==0)
        {
            done = 1;
            system("cls");
            pos.X = 20;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("New class: ");
            gets(line);
            strcpy(s->Class, line);
        }
        else if (strcmp(line, "math")==0)
        {
            done = 1;
            system("cls");
            pos.X = 20;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("Math mark: ");
            gets(line);
            if ((line[0]-'0'<=5) && (line[0]-'0'>=1) && (strlen(line)==1))
                s->mathMark= line[0]- '0';
        }
        else if (strcmp(line, "physics")==0)
        {
            done = 1;
            system("cls");
            pos.X = 20;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("Physics mark: ");
            gets(line);
            if ((line[0]-'0'<=5) && (line[0]-'0'>=1) && (strlen(line)==1))
                s->physicsMark= line[0]- '0';
        }
        else if (strcmp(line, "op")==0)
        {
            done = 1;
            system("cls");
            pos.X = 20;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("OP mark: ");
            gets(line);
            if ((line[0]-'0'<=5) && (line[0]-'0'>=1) && (strlen(line)==1))
                s->opMark= line[0]- '0';
        }
        else if (strcmp(line, "exit")==0)
        {
            done = 1;
        }
        else{}
    }
    system("cls");
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(handle, pos);
    printf("Name: %s", s->name);
    pos.X = 0;
    pos.Y = 1;
    SetConsoleCursorPosition(handle, pos);
    printf("Class: %s", s->Class);
    pos.X = 0;
    pos.Y = 2;
    SetConsoleCursorPosition(handle, pos);
    printf("Math mark: %i\n", s->mathMark);
    printf("Physics mark: %i\n", s->physicsMark);
    printf("OP mark: %i\n", s->opMark);
    system("pause");

}
void changeStudent()
{

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int n;
    char line[100];
    while(1)
    {
        system("cls");
        pos.X = 30;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        if (getN()==1)
            printf("There is only 1 student. Confirm(1)");
        else
            printf("Please, choose student's id(1-%i)", getN());
        editPlace();

        gets(line);
        n = line[0] -'0';
        if (strlen(line)>1)// если число имеет больше 1 цифры
            continue;
        if ((n>=1) && (n<=getN()))
            break;
    }
    struct student Student[getN()];
    readFile(getN(), Student);
    changeCurentStudent(&Student[n-1]);
    saveFile(getN(), Student);
}
void createCurentStudent(struct student *Student)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    system("cls");
    pos.X = 30;
    pos.Y = 10;
    char line[100];
    int n;
    SetConsoleCursorPosition(handle, pos);
    printf("Name: ");
    gets(line);
    strcpy(Student->name, line);

    system("cls");
    pos.X = 30;
    pos.Y = 10;
    SetConsoleCursorPosition(handle, pos);
    printf("Class: ");
    gets(line);
    strcpy(Student->Class, line);


    n=0;

    while((n<1) || (n>5))
    {
        system("cls");
        pos.X = 30;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        printf("Math mark: ");
        gets(line);
        if (strlen(line)!=1) // отсеивает случаи, при которых число имеет более 1 цифры
            continue;
        n= line[0]-'0';
    }
    Student->mathMark = line[0]-'0';

    n=0;

    while((n<1) || (n>5))
    {
        system("cls");
        pos.X = 30;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        printf("Physics mark: ");
        gets(line);
        if (strlen(line)!=1)
            continue;
        n= line[0]-'0';
    }
    Student->physicsMark = line[0]-'0';
    n=0;

    while((n<1) || (n>5))
    {
        system("cls");
        pos.X = 30;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        printf("OP mark: ");
        gets(line);
        if (strlen(line)!=1)
            continue;
        n= line[0]-'0';
    }
    Student->opMark = line[0]-'0';

}
void createStudent()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    struct student s[getN()+1];
    readFile(getN(), s);
    createCurentStudent(&s[getN()]);

    system("cls");
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(handle, pos);
    printf("Added:\n%s\nClass: %s\n", s[getN()].name, s[getN()].Class);
    printf("Math: %i. Physics: %i. OP: %i\n", s[getN()].mathMark, s[getN()].physicsMark, s[getN()].opMark);
    system("pause");
    saveFile(getN()+1, s);
}
void hello()
{
    int done =1;
    while (done)
    {
        system("cls");
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        int i;
        char str[100];
        pos.X = 30;
        pos.Y = 10;
        SetConsoleCursorPosition(handle, pos);
        printf("Commands: ");
        pos.X = 30;
        pos.Y = 11;
        SetConsoleCursorPosition(handle, pos);
        printf("1. Take a look at list of students (list)");
        pos.X = 30;
        pos.Y = 12;
        SetConsoleCursorPosition(handle, pos);
        printf("2. Change student (change)");
        pos.X = 30;
        pos.Y = 13;
        SetConsoleCursorPosition(handle, pos);
        printf("3. Add new student (add)");
        pos.X = 30;
        pos.Y = 14;
        SetConsoleCursorPosition(handle, pos);
        printf("Exit(exit)");
        editPlace();
        gets(str);
        if (strcmp(str, "list")==0)
        {
            showList();
        }
        else if (strcmp(str, "change")==0)
        {
            changeStudent();
        }
        else if (strcmp(str, "add")==0)
        {
            createStudent();
        }
        else if (strcmp(str, "exit")==0)
        {
            done = 0;
        }
        else
        {
            system("cls");
            pos.X = 30;
            pos.Y = 10;
            SetConsoleCursorPosition(handle, pos);
            printf("Wrong command");
            pos.X = 1;
            pos.Y = 20;
            SetConsoleCursorPosition(handle, pos);
            system("pause");
        }
    }


}
int main()
{
    system("color F0");
    hello();
    return 0;
}
