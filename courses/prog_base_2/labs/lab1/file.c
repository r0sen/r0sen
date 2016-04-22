#include "file.h"
#include "folder.h"

struct folder_s
{
    int size;
    file_t *files[10];
    folder_status_t status;
};

struct file_s
{
    char * data;
    file_stat_t status;
};

void fillData(folder_t* folder, file_t* file, char* data)
{
    if(folder == NULL || file == NULL)
        return;
    if(data == NULL)
    {
        file->status = FILE_IS_EMPTY;
        return;
    }

    file->data = (char*)malloc(FILE_SIZE * sizeof(char));//100 symbols in one string

    strcpy(file->data, data);

    file->status = FILE__IS_OK;
}

void deleteData(folder_t * folder, file_t * file)
{
    if(folder == NULL || file == NULL || folder->status == FOLDER_EMPTY || file->status == FILE_IS_EMPTY)
        return NULL;
    free(file->data);
    file->status = FILE_IS_EMPTY;
}

char * file_getData(folder_t * folder, file_t * file)
{
    if(folder == NULL || file == NULL || folder->status == FOLDER_EMPTY || file->status == FILE_IS_EMPTY)
        return;
    return file->data;
}

void freeFile(folder_t * folder, file_t* file)
{
    if(folder == NULL || file == NULL)
        return NULL;
    if(file->status == FILE_IS_EMPTY)
        return NULL;
    if(file_getStat(file) != FILE_IS_EMPTY)
        free(file->data);
    free(file);
    (folder->size)--;
}

file_stat_t file_getStat(file_t * file)
{
    return file->status;
}
