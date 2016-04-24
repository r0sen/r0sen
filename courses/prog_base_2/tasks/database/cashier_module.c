#ifndef TRUE
#define TRUE 1
#endif 
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sqlite3.h>
#include "cashier_module.h"
#include "cashier.h"


struct data_s
{
    sqlite3 * data;
};

static void _cashierFill(sqlite3_stmt * stmt, cashier_t *cashier)
{

    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    const unsigned char *surname = sqlite3_column_text(stmt, 2);
    int cash = sqlite3_column_int(stmt, 3);
    int months = sqlite3_column_double(stmt, 4);
    const unsigned char *birthDate = sqlite3_column_text(stmt, 5);
    cashier->id = id;
    strcpy(cashier->name, (char *)name);
    strcpy(cashier->surname, (char *)surname);
    cashier->cash = cash;
    cashier->months = months;
    strcpy(cashier->birthDate, (char *)birthDate);
}

data_t * database_new(char *dataPath)
{
    data_t * out = (data_t *) malloc(sizeof(struct data_s));
    int whatReturn = sqlite3_open(dataPath, &out->data);
    error_notEqual(whatReturn, SQLITE_OK, "Cant open .db\n");
    return (out);
}

void database_delete(data_t * this)
{
    int whatReturn = sqlite3_close(this->data);
    error_notEqual(whatReturn, SQLITE_OK, "Cant close .db\n");
    free(this);
}

void database_insertCashier(data_t * this, cashier_t * cashier)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlInsertCommand = "INSERT INTO Cashier ('Name', 'Surname', 'Cash', 'Months', 'Birthdate') VALUES (?,?,?,?,?);";
    int whatReturn = 0;
    whatReturn = sqlite3_prepare_v2(this->data, sqlInsertCommand, strlen(sqlInsertCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "Sql insert command wasn`t prepared.");
    sqlite3_bind_text(stmt, 1, cashier->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, cashier->surname, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, cashier->cash);
    sqlite3_bind_double(stmt, 4, cashier->months);
    sqlite3_bind_text(stmt, 5, cashier->birthDate, -1, SQLITE_STATIC);
    whatReturn = sqlite3_step(stmt);
    error_notEqual(whatReturn, SQLITE_DONE, "ERROR insert");
    cashier->id = (int)sqlite3_last_insert_rowid(this->data);
    sqlite3_reset(stmt);
}

cashier_t * database_getCashierById(data_t * this, int id)
{
    cashier_t *out = (cashier_t *)malloc(sizeof(struct cashier_s));
    sqlite3_stmt * stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Cashier WHERE Id=?;";
    int whatReturn = 0;
    sqlite3_prepare_v2(this->data, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "command wasn`t prepared.");
    sqlite3_bind_int(stmt, 1, id);
    whatReturn = sqlite3_step(stmt);
    if(whatReturn != SQLITE_ROW)
    {
        out->id = 0;
        strcpy(out->name, "Name");
        strcpy(out->surname, "Surname");
        out->cash = 0;
        out->months = 0.0;
        strcpy(out->birthDate, "Birthdate");
        return (out);
    }

    out->id = id;
    strcpy(out->name, (char *)sqlite3_column_text(stmt, 1));
    strcpy(out->surname, (char *)sqlite3_column_text(stmt, 2));
    out->cash = sqlite3_column_int(stmt, 3);
    out->months = sqlite3_column_double(stmt, 4);
    strcpy(out->birthDate, (char *)sqlite3_column_text(stmt, 5));
    sqlite3_reset(stmt);
    return (out);
}

void database_updateCashier(data_t * this, cashier_t * cashier, int id)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlUpdateCommand = "UPDATE Cashier SET "
                                   "Surname=?,"
                                   "Surname=?,"
                                   "Cash=?,"
                                   "Months=?,"
                                   "Birthdate=? "
                                   "WHERE Id=?;";
    int whatReturn = 0;
    whatReturn = sqlite3_prepare_v2(this->data, sqlUpdateCommand, strlen(sqlUpdateCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "Error preparing update command.");
    sqlite3_bind_text(stmt, 1, cashier->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, cashier->surname, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, cashier->cash);
    sqlite3_bind_double(stmt, 4, cashier->months);
    sqlite3_bind_text(stmt, 5, cashier->birthDate, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, id);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

void database_deleteCashierById(data_t * this, int id)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlDeleteCommand = "DELETE FROM Cashier WHERE Id=?";
    int whatReturn = 0;
    sqlite3_prepare_v2(this->data, sqlDeleteCommand, strlen(sqlDeleteCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "Error preparing to delete");
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

int database_countCashiers(data_t * this)
{
    sqlite3_stmt * stmt = NULL;
    const char *countCommand = "SELECT COUNT(*) FROM Cashier";
    int whatReturn = 0;
    int studentsCount = 0;
    whatReturn = sqlite3_prepare_v2(this->data, countCommand, strlen(countCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "   Error preparing\n");
    whatReturn = sqlite3_step(stmt);
    error_equal(whatReturn, SQLITE_ERROR, "   Error by stepping\n");
    studentsCount = sqlite3_column_int(stmt, 0);
    return (studentsCount);
}

int database_filterCashiers(data_t * this, int K, double P, cashier_t * cashierSet, int setMaxLen)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Cashier WHERE Cash > ? AND Months > ?;";
    int whatReturn = 0;
    int cashierSetIndex = 0;
    sqlite3_prepare_v2(this->data, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    error_notEqual(whatReturn, SQLITE_OK, "   Error preparing\n");
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_double(stmt, 2, P);
    while(TRUE)
    {
        int returnCode2 = sqlite3_step(stmt);
        if(returnCode2 == SQLITE_ERROR)
        {
            fprintf(stderr, "     Can`t select smth\n");
            exit(1);
        }
        if(SQLITE_DONE == returnCode2)
        {
            break;
        }
        else
        {
            _cashierFill(stmt, &cashierSet[cashierSetIndex]);
            cashierSetIndex++;
        }
    }
    whatReturn = sqlite3_finalize(stmt);
    error_notEqual(whatReturn, SQLITE_OK, "Error when destroy.");
    return (cashierSetIndex);
}

static void error_notEqual(int whatReturn, int error, const char *errMessage)
{
    if(error != whatReturn)
    {
        fprintf(stderr, "ERROR   : [%s].                    \n", errMessage);
        exit(1);
    }
}

static void error_equal(int whatReturn, int error, const char *errMessage)
{
    if(error == whatReturn)
    {
        fprintf(stderr, "ERROR   : [%s].                          \n", errMessage);
        exit(1);
    }
}
