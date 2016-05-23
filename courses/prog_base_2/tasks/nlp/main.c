#include <stdlib.h>
#include "analiz.h"
#include <ctype.h>
#include <stdio.h>
#include "stop_words.h"
#define STOPWORD_COUNT 151
int main()
{
    char title[] = "text.txt";
    FILE * file;
    if((file = fopen(title, "r")) == NULL)
        return 1;

    text_t * text = text_new();

    readFile(file,text);



    sentense_t * tmp;
    for (int i = 0; i < sentence_count(text); i++)
    {
        tmp = get_sentence(text, i);
        for (int j = 0; j < word_count(tmp); j++)
        {
            for( int stopw = 0; stopw < STOPWORD_COUNT; stopw++)
            {
                if(strcmp(get_word(sentence_get_word(tmp, j)), stop_words[stopw]) == 0 || strlen(get_word(sentence_get_word(tmp, j))) < 4)
                {
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
