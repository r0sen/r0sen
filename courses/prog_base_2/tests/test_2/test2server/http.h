#ifndef CASHIERS_H_INCLUDED
#define CASHIERS_H_INCLUDED


#define BUFFER_LENGTH 100000
#define MSG_LENGTH 10000
#define WORD_LENGTH 100
typedef enum resp_s {HTML, XML} resp_t;
typedef struct list_s list_t;
char *resp_form(resp_t type, char *usermsg, int code, char *buffer)

#endif

