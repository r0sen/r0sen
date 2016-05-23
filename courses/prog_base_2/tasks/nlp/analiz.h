#ifndef ANALIZ_H_INCLUDED
#define ANALIZ_H_INCLUDED

typedef struct text_s text_t;
typedef struct sentense_s sentense_t;
typedef struct word_s word_t;

void sentenseToText(text_t * sentense, sentense_t * words);
void wordToSentense(sentense_t * words, word_t * word);
sentense_t * get_sentence(text_t * text, int pos);
char * get_word(word_t * word);
word_t * sentence_get_word(sentense_t * sentense, int pos);

sentense_t * delete_sentense(text_t * text, int pos);
word_t * delete_word(sentense_t * sentense, int pos);
int word_count(sentense_t * sentense);
int sentence_count(text_t * text);

#endif // ANALIZ_H_INCLUDED
