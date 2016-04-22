#include "glossary.h"

struct gloss
{
    char word[30];
    int countOfThis;
};

struct gloss_s
{
    int countOfAll;
    glossary words[200];
};

gloss_t * newGloss(void)
{
    int i;
    gloss_t * glossy = malloc(sizeof(struct gloss_s));
    glossy->countOfAll = 0;
    for(i = 0; i<200; i++)
        glossy->words[i].countOfThis = 0;
    glossy->countOfAll = 0;
    return glossy;
}

void freeGloss(gloss_t * glossy)
{
    if(glossy == NULL)
        return NULL;
    free(glossy);
}

void fillInGlossary(gloss_t * glossy, folder_t * folder)
{
    int i;
    _Bool check = FALSE;
    char *str;
    //char * folderText = malloc(100 * sizeof(char));
    char folderText[100];
    strcpy(folderText, getData(folder));
    str = strtok(folderText, " .,?!;");
    while(str != NULL)
    {
        for(i = 0; i<glossy->countOfAll; i++)
        {
            if(strcmp(str, glossy->words[i].word) == 0)
            {
                check = TRUE;
                glossy->words[i].countOfThis++;
                break;
            }
            else
                continue;
        }
        if(!check)
        {
            strcpy(glossy->words[glossy->countOfAll].word, str);
            glossy->words[glossy->countOfAll].countOfThis++;//!!!!!
            glossy->countOfAll++;
        }
        check = FALSE;
        str = strtok(NULL, " .,?!;");
    }
    //free(folderText);
}

void outputGlossary(gloss_t * glossy)
{
    int i;
    if(glossy == NULL)
        return NULL;
    for(i = 0; i<glossy->countOfAll; i++)
    {
        printf("%s - %i\n", glossy->words[i].word, glossy->words[i].countOfThis);
    }
}
