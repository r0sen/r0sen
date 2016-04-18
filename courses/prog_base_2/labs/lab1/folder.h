#ifndef FOLDER_H_INCLUDED
#define FOLDER_H_INCLUDED

#include <stdlib.h>

#include "file.h"

typedef struct folder_s folder_t;
typedef struct file_s file_t;

folder_t * newFolder(void);
file_t * newFile(folder_t * folder);

void freeFolder(folder_t * folder);

char * getData(folder_t * folder);

int getSize(folder_t * folder);

typedef enum folder_status_t
{
    FOLDER_OK,
    FOLDER_EMPTY,
    FOLDER_FULL
} folder_status_t;

folder_status_t getStatus(folder_t * folder);

#endif // FOLDER_H_INCLUDED
