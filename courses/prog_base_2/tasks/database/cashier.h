#define MAX_NAME_LENGHT 256
#define MAX_SURNAME_LENGHT 256
#define MAX_BIRTHDAY_LENGHT 256

typedef struct cashier_s
{
    int id;
    char name[MAX_NAME_LENGHT];
    char surname[MAX_SURNAME_LENGHT];
    int cash;
    double months;
    char birthDate[MAX_BIRTHDAY_LENGHT];
} cashier_t;

void cashier_print(const cashier_t *this);
void cashier_printList(const cashier_t *cashSet, int cashCount);
