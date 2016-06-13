#include <stdio.h>
#include <stdlib.h>
#include "Oslib.h"
int main()
{
os_t *os = os_new("Okna");
program_t *program1 = program_new("First");
program_t *program2 = program_new("Second");
program_t *program3 = program_new("Third");
user_t *user1 = user_new("Vasya");
user_t *user2 = user_new("Senya");
user_t *user3 = user_new("Nadya");
os_addProgram(os,program1);
os_addProgram(os,program2);
os_addProgram(os,program3);
os_newUser(os,user1);
os_newUser(os,user2);
os_newUser(os,user3);
user_print(user1);


}
