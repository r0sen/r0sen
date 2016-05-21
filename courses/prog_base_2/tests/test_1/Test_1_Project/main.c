#include <stdio.h>
#include <stdlib.h>

#include "clinic.h"

typedef void (*start_fn)(clinic_t * clinic, doctor_t doctor, patient_t patient);


void startFunction(clinic_t * clinic, doctor_t doctor, patient_t patient) {



    printf("\Doctor %s u have new patient %s\n", doctor->name, patient->name,);
}

int main(void) {
    clinic_t clinic = clinic_new();

clinic_subscribe(clinic_t clinic, startFn);


    train_subscribeStart(train, user1, (start_fn)onTrainStarted);
    train_subscribeStart(train, user2, (start_fn)onTrainStarted);


    train_unsubscribeStart(train, NULL, onStart2);
    train_unsubscribeStart(train, user2, (start_fn)onTrainStarted);


    return 0;
}
