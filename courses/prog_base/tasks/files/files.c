#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void fprocess(const char * pread, const char * pwrite){
char str[200];
int i=0, bil, men;

FILE *fp;

fp = fopen(pread, "r");
while(i<12){
    fgets(str, 200, fp);
    i++;
}
fscanf(fp, "%i %i", &bil, &men);
fclose(fp);

float k = bil/men;
i = bil%men;

fp = fopen(pwrite, "w");
fprintf(fp, "%f %i", k, i);
fclose(fp);
}
