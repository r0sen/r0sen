#include "http.h"
#include "cashiers.h"
char*resp_form(resp_t type, char *usermsg, int code, char *buffer)
{
    char msg[MSG_LENGTH];
    if(type == XML)
    {
        switch(code)
        {
        case 200:
        {
            sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(usermsg), usermsg);
            break;
        }
        case 403:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 403: forbidden</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        case 404:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 404: not found</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        default:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 502: bad gateway</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 502 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        }
    }
    else if (type == HTML)
    {
        switch(code)
        {
        case 200:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title></title>" //!REMEMBER TO SET YOUR TITLE!
                    "</title>"
                    "</head>"
                    "<body>"
                    "%s"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        case 403:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>403 forbidden</title>" //!REMEMBER TO SET YOUR TITLE!
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 403: forbidden</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        case 404:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>404 not found</title>" //!REMEMBER TO SET YOUR TITLE!
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 404: not found</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 404 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        default:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>502 bad gateway</title>" //!REMEMBER TO SET YOUR TITLE!
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 502: bad gateway</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 502 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
    }
    return buffer;
}
