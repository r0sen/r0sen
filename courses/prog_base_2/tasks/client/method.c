#include <winsock2.h>
#include <windows.h>
#include "method.h"
#define MAXBUFLEN 20480
#define NO_FLAGS_SET 0

char *method_request(SOCKET recvSocket, const char request [], char buffer [], int maxLen){
    send(recvSocket, request, strlen(request), 0);

    int numrcv = 0;
    int status = 0;
    int i;
    for (i=0; i<MAXBUFLEN; i++){
        buffer[i] = 0;
    }

    numrcv = recv(recvSocket, buffer, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
			printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
			printf("ERROR: WsaCleanup unsuccessful\r\n");
        system("pause");
        return(1);
    }

    printf("%s\r\n", buffer);

    return buffer;
}

char * method_secret(char * buffer_p){
    char *p;
    char delete[] = "=";
    p = strtok(buffer_p, delete);
    p = strtok(NULL, delete);
    p = strtok(NULL, delete);

    printf("\nSecret word is '%s'\n\n", p);
    return p;
}

void method_list(char * list, char * buffer_p){
    int i = 0;
    int j = 0;
    while (j<6){ 
        if (buffer_p[i++]=='\n'){
            j++;
        }
    }

    strcpy(list, buffer_p+i);
    return;
}

void method_getMaxCount(char * list, int size, char *sumLine){
    int max = -1;
 
 int i,j,k,h=0,s=0,t=0,f=0;
    char str[100];
    char delete[] = " ";
	char names[100][100];
	
	int filled = -1;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			names[i][j] = '-';
		}
	}
	char name [100];
	int counter[100];
	for (j = 0; j < 100; j++)
		counter[j] = 0;
int first,last;

i = 0;
   while(i < size)
   {
			 while(list[i]!=' ')
				i++;
			for (j = 0; j < 100; j++)
				name[j] = '-';
			i++;
			j = 0;
			while(list[i]!= ' ')
			{
				name[j] = list[i];
				j++;
				i++;
			}
			int wasFound = 0;
			for (j = 0; j <= filled; j++)
			{
				if (strcmp(names[j], name) == 0)
				{
					counter[j]++;
					wasFound = 1;
					break;
				}
			}
			if (wasFound == 0)
			{
				filled++;
				strcpy(name[filled], name);
				counter[filled]++;
			}
			
			
			 i++;
   }
   
   for (i = 0; i < 100; i++)
   {
	   if (counter[i] > max)
		   max = counter[i];
   }
	   sprintf(sumLine, "%i", max);
	return ;
}