#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <time.h>
#include "cashiers.h"
#include "http.h"


char *first_task_func(void){
    xmlDoc *doc = NULL;
    xmlNode * rootNode = NULL;
    xmlNode *textNode = NULL;
    doc = xmlNewDoc("1.0");
    rootNode = xmlNewNode(NULL, "message");
    xmlDocSetRootElement(doc, rootNode);
    char buff[1000];
    xmlNewChild(rootNode, NULL, "status", "OK");
    textNode = xmlNewChild(rootNode, NULL, "text", NULL);
    xmlNewChild(textNode, NULL, "student", "Denys Medvedskyi");
    xmlNewChild(textNode, NULL, "group", "KP-51");
    xmlNewChild(textNode, NULL, "variant", "5");
    xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlBufferFree(bufferPtr);
    return buff;
}

char *second_task_func(char *stuff){
    char author[100];
    char book[100];
    char buff[1000];
    time_t ptimer;
    xmlDoc *rcv = xmlReadMemory(stuff, strlen(stuff), NULL, NULL, 0);
    xmlDoc *rst = xmlNewDoc("1.0");
    xmlNode * xRootEl;
    xmlNode *textNode = NULL;
    xmlNode *respRootNode = xmlNewNode(NULL, "message");
    xmlDocSetRootElement(rst, respRootNode);

    xmlNewChild(respRootNode, NULL, "status", "OK");

    textNode = xmlNewChild(respRootNode, NULL, "text", NULL);

    xRootEl = xmlDocGetRootElement(rcv);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ;xCur = xCur->next){
        const char *name = xCur->name;
        const char *content = xmlNodeGetContent(xCur);
        xmlNewChild(textNode, NULL, name, content);
    }

	struct tm *cl1 = malloc(sizeof(struct tm));
	cl1 = localtime(&ptimer);
    xmlNewChild(textNode, NULL, "recieving_time", asctime(cl1));
    xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)rst, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    xmlFreeDoc(rst);
    xmlFreeDoc(rcv);
	xmlCleanupParser();
	xmlBufferFree(bufferPtr);
    return buff;
}
/*void http_sendHtml(socket_t *client, char *htmlPath)
{
    char pageContentToReceive[100000];
    FILE *f = fopen(htmlPath, "r");
    int len = fread(pageContentToReceive, 1, sizeof(pageContentToReceive), f);
    pageContentToReceive[len] = '\0';

    char pageContentToSend[1024];
    sprintf(pageContentToSend,
            "HTTP/1.1 %s\n"
            "Content-Type: text/html\n"
            "Content-Length: %d\n"
            "Connection: keep-alive\r\n\r\n"
            "\n%s",
            (strstr(pageContentToReceive, "404 page</title>") == NULL) ? "200 OK" : "404",
            strlen(pageContentToReceive),
            pageContentToReceive);
    socket_write_string(client, pageContentToSend);

    fclose(f);
    socket_close(client);
}*/
