#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "cashiers.h"

char *mine_to_message(void){
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



