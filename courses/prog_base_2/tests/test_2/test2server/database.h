#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "sqlite3.h"
#include "cashiers.h"

enum errors{STEP_ERROR, INVALID_REQUEST, PROCESS_FAILURE};

void read_cashier(sqlite3 *db, int id, cashier_t *self, int *err);
int create_cashier(sqlite3 *db, cashier_t *self, int *err);
int delete_cashier(sqlite3 *db, int id, int *err);
int update_cashier(sqlite3 *db, int id, cashier_t *self, int *err);
void select_cashiers(sqlite3 *db, int filter1, double filter2, int *err);
int cashiers_count(sqlite3 *db, int *err);


#endif // DATABASE_H_INCLUDED
