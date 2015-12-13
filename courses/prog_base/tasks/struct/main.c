#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Emails {
   int text;
   int id;
   char title[100];
};

int count(int size, struct Emails arr[size]){
    int i, amount=0;
    for (i=0; i<size; i++){
        if (arr[i].text>140){
            amount++;
        }
    }
    return amount;
}

void change(struct Emails * pVar, const char * newValue){
    strcpy(pVar->title, newValue);
}

void print(struct Emails * pVar){
   printf("Size of characters in letter: %i\nTitle of e-mail: %s\nId of e-mail: %i\n\n", pVar->text, pVar->title, pVar->id);
}

int main(void){
     int i, size=3;
     char newname[100];
     struct Emails arr[3]={{140, 13456, "OP KP-51 Lab1"},{141, 36753, "OP KP-52 Lab1"},{231, 67584, "OP KP-51 Lab2"}};

     for(i=0;i<size;i++){
        print(&arr[i]);
     }

     printf("Size of letters, where size of characters > 140: %i\n\n", count(3, arr));
     printf("Enter the index of letter: ");
     scanf("%i", &i);
     if (i>=size||i<0){
        printf("Failed index of letter");
        return 1;
     }
     printf("Enter the new title of e-mail: ");
     gets(newname);
     gets(newname);

     puts("");
     change(&(arr[i]), newname);
     print(&arr[i]);

     return 0;
}
