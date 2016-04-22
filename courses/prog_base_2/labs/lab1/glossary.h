#ifndef GLOSSARY_H_INCLUDED
#define GLOSSARY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "folder.h"
#include "file.h"

typedef struct gloss glossary;
typedef struct gloss_s gloss_t;

gloss_t * newGloss(void);

void freeGloss(gloss_t * glossy);

void fillInGlossary(gloss_t * glossy, folder_t * folder);
void outputGlossary(gloss_t * glossy);
#endif // GLOSSARY_H_INCLUDED
