#include "folder.h"
#include "file.h"


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

folder_t * newFolder(void)
{
    folder_t * folder = malloc(sizeof(struct folder_s));
    folder->size = 0;
    folder->status = FOLDER_EMPTY;
    return folder;
}

file_t * newFile(folder_t * folder)
{
    if(folder == NULL)
        return NULL;
    if(folder->size == 10)
    {
        folder->status = FOLDER_FULL;
        return NULL;
    }
    if(folder->size + 1 == 10)
    {
        folder->status = FOLDER_FULL;
    }

    file_t * file = malloc(sizeof(struct file_s));

    folder->files[(folder->size)++] = file;

    folder->status = FOLDER_OK;
    file->status = FILE_IS_EMPTY;
    return file;
}

void freeFolder(folder_t * folder)
{
    int i;
    if(folder == NULL)
        return NULL;
    if(folder->status != FOLDER_EMPTY)
    {
        for(i=folder->size-1 ; i>=0; i--)
            freeFile(folder, folder->files[i]);
    }
    free(folder);
}

char * getData(folder_t * folder)
{
    int i;
    if(folder == NULL)
        return;
    char folderData[300];
    for(i = 0; i<folder->size; i++)
    {
        if(file_getStat(folder->files[i]) == FILE_IS_EMPTY)
            continue;
        if(i == 0)
        {
            strcpy(folderData, file_getData(folder, folder->files[i]));
            continue;
        }
        strcat(folderData, " ");
        strcat(folderData, file_getData(folder, folder->files[i]));
    }
    return folderData;
}

int getSize(folder_t * folder)
{
    return folder->size;
}

folder_status_t getStatus(folder_t * folder)
{
    return folder->status;
}
