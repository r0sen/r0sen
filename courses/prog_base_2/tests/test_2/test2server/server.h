#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "cashiers.h"
#include "socket.h"
#include "database.h"

typedef struct keyvalue_s keyvalue_t;
typedef struct http_request_s http_request_t;

http_request_t
http_parse(const char * const request);

const char *
http_request(http_request_t * self, const char * key);

const char *
keyvalue_toString(keyvalue_t * self);

void startServer(list_t *list);

#endif // SERVER_H_INCLUDED
