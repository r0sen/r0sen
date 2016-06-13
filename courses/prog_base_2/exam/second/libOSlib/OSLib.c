#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "OSlib.h"

// Constructors and destructors.
program_t *program_new(const char *name)
{
    program_t *pr = (program_t *) malloc (sizeof(struct program_s));
    // Program's id.
    pr->id = -1;
    // Program's name.
    sprintf(pr->name, name);
    // If program is not used now, field userId equals to -1.
    pr->userId = -1;
    // Return ready program.
    return (pr);
}
void program_delete(program_t *program)
{
    free (program);
}
void program_print(program_t *program)
{
    printf("%d: %s\n", program->id, program->name);
    if (program->userId != -1)
        printf("Used by user with id %s.\n", program->id);
    else
        printf("Not used by anyone.\n");
}

user_t *user_new(const char *name)
{
    user_t *usr = (user_t *) malloc(sizeof(struct user_s));
    // User's id.
    usr->id = -1;
    // User's name.
    sprintf(usr->name, name);
    // Field to describe if user is logged in.
    usr->isLoggedIn = 0;
    // Return ready user.
    return (usr);
}
void user_delete(user_t *user)
{
    free (user);
}
void user_print(user_t *user)
{

    printf("%d: %s\n", user->id, user->name);
    if (user->isLoggedIn == 1)
        printf("User is logged in.\n");
    else
        printf("User is not logged in.\n");
}

os_t *os_new()
{
    os_t *os = (os_t *)malloc(sizeof(struct os_s));
    for (int i = 0; i < USERS_MAX_COUNT; i++)
        os->users[i] = user_new("noname");
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
        os->programs[i] = program_new("noname");
    return (os);
}

void os_delete(os_t *os)
{
    for (int i = 0; i < USERS_MAX_COUNT; i++)
        user_delete(os->users[i]);
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
        program_delete(os->programs[i]);
    free(os);
}

// Other.
void os_addProgram(os_t *os, program_t *program)
{
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        if (os->programs[i]->id == -1) {
            os->programs[i] = program;
            os->programs[i]->id = i + 1;
        }
    }
}

// Task #1
int os_getUsersCount(const os_t *os)
{
    int usersCount = 0;
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->id != -1)
            usersCount++;
    }
    return (usersCount);
}
user_t **os_getUsersList(os_t *os)
{
    return (os->users);
}

// Task #2
void os_newUser(os_t *os, user_t *newUser)
{
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->id == -1)
        {
            os->users[i] = newUser;
            os->users[i]->id = i + 1;
        }
    }
}

// Task #3
void os_deleteUser(os_t *os, int userId)
{
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->id == userId)
        {
            if (!strcmp(os->users[i]->name, "noname"))
                break;
            os->users[i]->id = -1;
            return;
        }
    }
    fprintf(stderr, "User by id %d is not found!\n", userId);
}

// Task #4
void os_logUserIn(os_t *os, int userId)
{
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->id == userId)
        {
            os->users[i]->isLoggedIn = 1;
            printf("User %s logged in.\n", os->users[i]->name);
            return;
        }
    }
    fprintf(stderr, "User by id %d is not found!\n", userId);
}

// Task #5
void os_logUserOut(os_t *os, int userId)
{
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->id == userId)
        {
            os->users[i]->isLoggedIn = 0;
            printf("User %s logged out.\n", os->users[i]->name);
            return;
        }
    }
    fprintf(stderr, "User by id %d is not found!\n", userId);
}

// Task #6
int os_getActiveUsersCount(const os_t *os)
{
    user_t **activeUsers = os_getActiveUsersList(os);
    int activeUsersCount = 0;
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (activeUsers[i]->isLoggedIn == 1)
            activeUsersCount++;
    }
    return (activeUsersCount);
}
user_t **os_getActiveUsersList(const os_t *os)
{
    user_t *activeUsers[USERS_MAX_COUNT];
    for (int i = 0; i < USERS_MAX_COUNT; i++)
        activeUsers[i] = user_new("noname");
    for (int i = 0; i < USERS_MAX_COUNT; i++)
    {
        if (os->users[i]->isLoggedIn == 1)
        {
            activeUsers[i] = os->users[i];
        }
    }
    return (activeUsers);
}

// Task #7
int os_getProgramsCount(const os_t *os)
{
    int programsAmount = 0;
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        if (os->programs[i]->id != -1)
            programsAmount++;
    }
    return (programsAmount);
}
program_t **os_getProgramsList(os_t *os)
{
    return (os->programs);
}

// Task #8
void os_turnOnProgram(os_t *os, int userId, int programId)
{
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        if (os->programs[i]->id == programId)
        {
            // Check if this program isn't turned on by another user.
            if (os->programs[i]->userId != userId)
            {
                os->programs[i]->userId = userId;
                return;
            }
            else
            {
                printf("Program %s is turned on by user with id %d!\n", os->programs[i]->name, userId);
                return;
            }
        }
    }
    fprintf(stderr, "Program by id %d is not found!\n", programId);
}

// Task #9
void os_turnOffProgram(os_t *os, int programId)
{
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        if (os->programs[i]->id == programId)
        {
            os->programs[i]->userId = -1;
            return;
        }
    }
    fprintf(stderr, "Program by id %d is not found!\n", programId);
}

// Task #10
program_t **os_getActivePrograms(os_t *os)
{
    program_t *activeProgramsList[PROGRAMS_MAX_COUNT];
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        activeProgramsList[i] = program_new("noname");
    }
    for (int i = 0; i < PROGRAMS_MAX_COUNT; i++)
    {
        if (os->programs[i]->userId != -1)
        {
            activeProgramsList[i] = os->programs[i];
        }
    }
    return (activeProgramsList);
}
int get_userId(user_t * user)
{
    if(user->id != -1)
    return user->id;
    else return -128;
}
