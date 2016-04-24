

#include "cashier.h"

typedef struct data_s data_t;

data_t * database_new(char *dataPath);
void database_delete(data_t * this);
void database_insertCashier(data_t * this, cashier_t * cashier);
cashier_t * database_getCashierById(data_t * this, int id);
void database_updateCashier(data_t * this, cashier_t * cashier, int id);
void database_deleteCashierById(data_t * this, int id);
int database_countCashiers(data_t * this);
int database_filterCashiers(data_t * this, int K, double P, cashier_t * cashierSet, int setMaxLen);
