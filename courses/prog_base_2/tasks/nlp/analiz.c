#include "analiz.h"
#include "list/list.h"
#include <stdio.h>

struct text_s
{
    list_t * sentense;
};
struct sentense_s
{
    list_t * words;
};
struct word_s
{
    char * word;
};



text_t * text_new()
{
    text_t * self = malloc(sizeof(text_t));
    self->sentense = list_new();
    return self;
}
sentense_t * sentense_new()
{
    sentense_t * self = malloc(sizeof(sentense_t));
    self->words = list_new();
    return self;
}
word_t * word_new(char * word)
{
    word_t * self = malloc(sizeof(word_t));
    self->word = malloc(sizeof(char)*strlen(word));
    strcpy(self->word, word);
    return self;
}
int sentence_count(text_t * text)
{
    return list_getSize(text->sentense);
}
int word_count(sentense_t * sentense)
{
    return list_getSize(sentense->words);
}
void sentenseToText(text_t * sentense, sentense_t * words)
{
    list_push_back(sentense->sentense, words);
}
sentense_t * get_sentence(text_t * text, int pos)
{
    return (sentense_t *)list_get(text->sentense, pos);
}
void wordToSentense(sentense_t * words, word_t * word)
{
    list_push_back(words->words, word);
}

word_t * delete_word(sentense_t * sentense, int pos)
{
    return (word_t *)list_remove(sentense->words, pos);
}
void fill_file(text_t * sentense)
{
    char title[] = "text_final.txt";

    FILE * file;
    file = fopen(title, "w");
    for(int i = 0; i < list_getSize(sentense->sentense); i++)
    {

        sentense_t * words = (sentense_t *)list_get(sentense->sentense, i);

        for(int j = 0; j < list_getSize(words->words); j++)
        {
            fprintf(file, "\n");

            word_t * word = (word_t * )list_get(words->words, j);

            fprintf(file, "%s",  word->word);
        }


        printf("test_final filling\n");
    }

    fclose(file);
}
word_t * sentence_get_word(sentense_t * sentense, int pos)
{
    return (word_t *)list_get(sentense->words, pos);
}




void text_free(text_t * sentense)
{

    list_free(sentense->sentense);
}
sentense_t * delete_sentense(text_t * text, int pos)
{
    return (sentense_t *)list_get(text->sentense, pos);
}

char * get_word(word_t * word)
{
    return word->word;
}

void readFile(FILE * file, text_t *text)
{
    sentense_t * sentenseCall = sentense_new();


    int curLenght = 0;
    char puttword[30] ;
    memset(puttword, 0, 30);
    char symbol;




    while((symbol = fgetc(file)) != EOF)
    {


        if(symbol == '.' || symbol == '?' || symbol == '!' )
        {
            if(curLenght == 0)
                continue;

            wordToSentense(sentenseCall, word_new(puttword));

            sentenseToText(text, sentenseCall);
            sentenseCall = sentense_new();
            memset(puttword, 0, 30);
            curLenght = 0;
        }


        if(symbol == ' ')
        {

            if(curLenght == 0)
                continue;

            wordToSentense(sentenseCall, word_new(puttword));
            memset(puttword, 0, 30);
            curLenght = 0;
        }

        else
        {


            puttword[curLenght] = symbol;
            curLenght++;
        }
    }

}
