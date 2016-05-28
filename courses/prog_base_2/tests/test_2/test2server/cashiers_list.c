#include<stdlib.h>
#include<string.h>

#include "cashiers.h"


typedef struct node_s node_t;


struct list_s{
    int count;
    node_t *head;
    node_t *tail;
};

struct node_s {
    node_t *next;
    node_t *prev;
    int id;
    cashier_t *contents;
};

cashier_t *new_cashier(void){
    cashier_t *newCashier = malloc(sizeof(struct cashier_s));
    return newCashier;
}

void free_cashier(cashier_t *self){
    free(self);
}


node_t *node_new(cashier_t *content, int id){
    node_t *node = malloc(sizeof(struct node_s));
    node->contents = content;
    node->next = NULL;
    node->prev = NULL;
    node->id = id;
    return node;
}


list_t *list_new(void){
    list_t *list = malloc(sizeof(struct list_s));
    list->count = 0;
    list->head = node_new(NULL, -1);
    list->tail = node_new(NULL, -1);
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

int list_add(list_t *base, cashier_t *self){
    if(list_find(base, self) != -1)
        return 0;
    node_t *newNode = node_new(self, ++(base->tail->id) + 1);
    node_t *curr = base->tail->prev;
    base->tail->prev = newNode;
    newNode->prev = curr;
    curr->next = newNode;
    newNode->next = base->tail;
    base->count++;
    return newNode->id;
}

int list_find(list_t *base, cashier_t *self){
    if(!base->count)
        return -1;
    node_t *curr = base->head->next;
    int i = 0;
    while(NULL != curr->next){
        if(curr->next->contents == self)
            return i;
        curr = curr->next;
        i++;
    }
    return -1;
}

cashier_t *list_get(list_t *base, int index){
    if(!base)
        return NULL;
    if(index < 0)
        index = -index;
    if(index >= base->count)
        return NULL;
    node_t *curr = base->head->next;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr->contents;
}

int list_count(list_t *self){
    return self->count;
}

cashier_t *list_remove(list_t *base, int index){
    if(!base)
        return NULL;
    if(index < 0)
        index = -index;
    if(index >= base->count || base->count == 0)
        return NULL;
    node_t *curr = base->head->next;
    if(index == 0){
        base->head->next = curr->next;
        curr->next->prev = curr->prev;
        cashier_t *teach = curr->contents;
        base->count--;
        free(curr);
        return teach;
    }
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    cashier_t *teach = curr->contents;
    base->count--;
    free(curr);
    return teach;
}

int list_find_id(list_t *self, int id){
    if(!self)
        return -1;
    node_t *curr = self->head;
    for(int i = 0; i < self->count; i++){
        curr = curr->next;
        if(curr->id == id)
            return i;
    }
    return -1;
}

int list_id(list_t *self, int index){
    if(!self)
        return -1;
    node_t *curr = self->head;
    for(int i = 0; i <= index; i++){
        curr = curr->next;
    }
    return curr->id;
}

void list_free(list_t *self){
    if(!self)
        return;
    while(self->count){
        free_cashier(list_remove(self, 0));
    }
    free(self->head);
    free(self->tail);
    free(self);
}
