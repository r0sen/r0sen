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


/*char *cashier_to_message(cashier_t *self, int id){
    if(!self)
        return NULL;
    char buff[MSG_LENGTH];
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * cashierNode = NULL;
	xmlNode * cathedraNode = NULL;
    doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "cashiers");
	xmlDocSetRootElement(doc, rootNode);
	char strBuf[100];
	cashierNode = xmlNewChild(rootNode, NULL, "cashier", NULL);
	sprintf(strBuf, "%i", id);
	xmlNewChild(cashierNode, NULL, "id", strBuf);
	xmlNewChild(cashierNode, NULL, "firstName", self->name);
	xmlNewChild(cashierNode, NULL, "lastName", self->surname);
	xmlNewChild(cashierNode, NULL, "pensionDate", self->date);
	sprintf(strBuf, "%i", self->hours);
	xmlNewChild(cashierNode, NULL, "hours", strBuf);
	sprintf(strBuf, "%f", self->rating);
	xmlNewChild(cashierNode, NULL, "rating", strBuf);
	cathedraNode = xmlNewChild(cashierNode, NULL, "cathedra", NULL);
	xmlNewProp(cathedraNode, "name", self->cathedra->name);
	xmlNewChild(cathedraNode, NULL, "speciality", self->cathedra->speciality);
	xmlNewChild(cathedraNode, NULL, "group", self->cathedra->groups[0]);
	xmlNewChild(cathedraNode, NULL, "group", self->cathedra->groups[1]);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlBufferFree(bufferPtr);
    return buff;
}*/

/*char *all_cashiers_to_message(list_t *list){
    if(list_count(list) == 0){
        return NULL;
    }
    char buff[MSG_LENGTH];
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
    doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "cashiers");
	xmlDocSetRootElement(doc, rootNode);
	char strBuf[100];
    for(int i = 0; i  < list_count(list); i++){
        cashier_t *self = list_get(list, i);
        int id = list_id(list, i);
        xmlNode * cashierNode = NULL;
        xmlNode * cathedraNode = NULL;
        cashierNode = xmlNewChild(rootNode, NULL, "cashier", NULL);
        sprintf(strBuf, "%i", id);
        xmlNewChild(cashierNode, NULL, "id", strBuf);
        xmlNewChild(cashierNode, NULL, "firstName", self->name);
        xmlNewChild(cashierNode, NULL, "lastName", self->surname);
        xmlNewChild(cashierNode, NULL, "pensionDate", self->date);
        sprintf(strBuf, "%i", self->hours);
        xmlNewChild(cashierNode, NULL, "hours", strBuf);
        sprintf(strBuf, "%f", self->rating);
        xmlNewChild(cashierNode, NULL, "rating", strBuf);
        cathedraNode = xmlNewChild(cashierNode, NULL, "cathedra", NULL);
        xmlNewProp(cathedraNode, "name", self->cathedra->name);
        xmlNewChild(cathedraNode, NULL, "speciality", self->cathedra->speciality);
        xmlNewChild(cathedraNode, NULL, "group", self->cathedra->groups[0]);
        xmlNewChild(cathedraNode, NULL, "group", self->cathedra->groups[1]);
    }
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    return buff;
}*/
