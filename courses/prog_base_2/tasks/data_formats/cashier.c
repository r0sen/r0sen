#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>

#include "cashier.h"

static cashier_t* cashier_function(cashier_t* current, xmlNode* curNode){
    char *data;
    char *properties;

    properties = (char *) xmlGetProp(curNode, (const xmlChar *)"name");
    strcpy(current->name, properties);
    properties = (char *)xmlGetProp(curNode, (const xmlChar *)"surname");
    strcpy(current->surname, properties);
    for(curNode = curNode->children; curNode != NULL; curNode = curNode->next)
    {
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"birthday"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            sscanf(data, "%d-%d-%d",
                   &current->birthday.tm_year,
                   &current->birthday.tm_mday,
                   &current->birthday.tm_mon);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"salary"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            current->salary = atof(data);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"cashboxID"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            current->cashboxID = atoi(data);
            continue;
        }
    }
    return current;
}

cashier_t* cashier_new()
{
    cashier_t* cashier = (cashier_t *)malloc(sizeof(struct cashier_s));
    strcpy(cashier->name, "");
    strcpy(cashier->surname, "");
    memset(&cashier->birthday, 0, sizeof(cashier->birthday));
    cashier->salary = 0.0;
    cashier->cashboxID = -1;
    return cashier;
}

void cashier_delete(cashier_t* cashier)
{
    free(cashier);
}

void xmlParse(cashier_t* cashierSet[], const char* XMLFileName)
{
    xmlDoc * doc = xmlReadFile(XMLFileName, "UTF-8", 0);
    if(doc == NULL)
    {
        xmlFreeDoc(doc);
        return;
    }
    xmlNode *xml_root = xmlDocGetRootElement(doc);
    xmlNode *curNode;
    int i;
    for(i = 0, curNode = xml_root->children; curNode != NULL; curNode = curNode->next)
    {
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"cashier"))
        {
            cashier_function(cashierSet[i++], curNode);
        }
    }
    xmlFreeDoc(doc);
}

void print_function(cashier_t* cashier){
    printf("\t[%s]\n"
           "\t[%s]\n"
           "\t[%s]\n"
           "\t%d-%d-%d\n"
           "\t%f\n"
           "\t%i\n"
           "\t[%s]\n"
           "\t%i\n\n",
           cashier->name,
           cashier->surname,
           cashier->birthday.tm_year, cashier->birthday.tm_mon, cashier->birthday.tm_mday,
           cashier->salary,
           cashier->cashboxID
          );
}
