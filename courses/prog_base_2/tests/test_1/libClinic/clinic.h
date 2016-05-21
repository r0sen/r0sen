#ifndef CLINIC_H_INCLUDED
#define CLINIC_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include "list/list.h"

typedef struct clinic_s clinic_t;
typedef struct patient_s patient_t;
typedef struct doctor_s doctor_t;


typedef enum {
CLINIC_FULL,
CLINIC_FREE,
CLINIC_OK
} clinic_status_t;

typedef enum {
   PATIENT_HEALTHY,
   PATIENT_UNWELL,
   PATIENT_ILL,
   PATIENT_CLINICD
} patient_status_t;

patient_t * patient_new(char* name);
doctor_t * doctor_new(char* name);
void patient_free(patient_t * self);
void patient_free(patient_t * self);
void patient_delete(clinic_t *clinic, patient_t * patient);
void doctor_delete(clinic_t *clinic, doctor_t * doctor);
void doctor_addPatient(clinic_t clinic,doctor_t doctor, patient_t *patient);
void clinic_addPatient(clinic_t * self, patient_t * patient);
void clinic_addDoctor(clinic_t * self, doctor_t * doctor);
clinic_t * clinic_new();
void clinic_free(clinic_t * self);
/*typedef void (*start_fn)(
    clinic_t * clinic,
    doctor_t doctor,
    patient_t patient);
*/
//void doctor_subscribeStart(clinic_t * self, void * listener, start_fn callback);
//void train_unsubscribeStart(train_t * self, void * listener, start_fn callback);


#endif // TRAIN_H_INCLUDED
