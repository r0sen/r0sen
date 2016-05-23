#include <stdio.h>
#include <stdlib.h>
#include "analiz.h"
#include <ctype.h>
#include "stop_words.h"
#define STOPWORD_COUNT
int main(){

    const char name[] = "text.txt";
    FILE * file;
    file = fopen(name, "r");
    if(file == NULL)
        return 1;

    int curLenght = 0;
    char word[25] = "";
    char symbol;

    text_t * text = text_new();
    sentense_t * sentenseCall = sentense_new();
    while((symbol = fgetc(file)) != EOF){
            if(symbol == '.' || symbol == '?' || symbol == '!' ){
                if(curLenght == 0)
                    continue;
                wordToSentense(sentenseCall, word_new(word));
                sentenseToText(text, sentenseCall);
                sentenseCall = sentense_new();
            memset(word, 0, 30);
                curLenght = 0;
            }
        else if(symbol == ' '){
            if(curLenght == 0)
                continue;
            wordToSentense(sentenseCall, word_new(word));
            memset(word, 0, 30);
            curLenght = 0;
        }
        else{
            word[curLenght] = symbol;
            curLenght++;
        }
    }

    sentense_t * tmp = NULL;
    for (int i = 0; i < sentence_count(text); i++)
    {
        tmp = get_sentence(text, i);
        for (int j = 0; j < word_count(tmp); j++)
        {
            for( int k = 0; k < 150; k++){
                if(strcmp(get_word(sentence_get_word(tmp, j)), stop_words[k]) == 0 || strlen(get_word(sentence_get_word(tmp, j))) < 4){
                    delete_word(tmp, j);
                    j--;
                    break;
                }
            }
        }
    }

    fclose(file);
    fill_file(text);
    text_free(text);
    return 0;
}
