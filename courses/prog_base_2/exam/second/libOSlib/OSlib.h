#pragma once

#define PROGRAMS_MAX_COUNT 100
#define USERS_MAX_COUNT 100
#define PROGRAM_NAME_MAX_LEN 1000
#define USERNAME_MAX_LEN 100

typedef struct program_s {
    int id;
    char name[PROGRAM_NAME_MAX_LEN];
    int userId;
} program_t;

typedef struct user_s {
    int id;
    char name[USERNAME_MAX_LEN];
    int isLoggedIn;
} user_t;

typedef struct os_s {
    user_t *users[USERS_MAX_COUNT];
    program_t *programs[PROGRAMS_MAX_COUNT];
} os_t;

// Constructors.
program_t *program_new(const char *name);
user_t *user_new(const char *name);
os_t *os_new();
// Destructors.
void os_delete(os_t *os);
void user_delete(user_t *user);
void program_delete(program_t *program);
// Printing
void user_print(user_t *user);
void program_print(program_t *program);

// Other
void os_addProgram(os_t *os, program_t *program);

// Task #1
int os_getUsersCount(const os_t *os);
user_t **getUsersList(os_t *os);
// Task #2
void os_newUser(os_t *os, user_t *newUser);
// Task #3
void os_deleteUser(os_t *os, int userId);
// Task #4
void os_logUserIn(os_t *os, int userId);
// Task #5
void os_logUserOut(os_t *os, int userId);
// Task #6
int os_getActiveUsersCount(const os_t *os);
user_t **os_getActiveUsersList(const os_t *os);
// Task #7
int os_getProgramsCount(const os_t *os);
program_t **os_getProgramsList(os_t *os);
// Task #8
void os_turnOnProgram(os_t *os, int userId, int programId);
// Task #9
void os_turnOffProgram(os_t *os, int programId);
// Task #10
program_t **os_getActivePrograms(os_t *os);
int get_userId(user_t * user);
