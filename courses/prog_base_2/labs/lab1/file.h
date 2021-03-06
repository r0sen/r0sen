#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <strings.h>
#include <stdlib.h>
#include "folder.h"

#define FILE_SIZE 200

typedef struct folder_s folder_t;
typedef struct file_s file_t;

void file_fillData(folder_t * folder, file_t * file, char* data);
void file_deleteData(folder_t * folder, file_t * file);

char * file_getData(folder_t * folder, file_t * file);

void file_freeFile(folder_t * folder, file_t * file);

typedef enum file_stat_t
{
    FILE__IS_OK,
    FILE_IS_EMPTY
} file_stat_t;

file_stat_t file_getStat(file_t * file);
#endif // FILE_H_INCLUDED
