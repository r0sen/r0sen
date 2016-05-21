#include "clinic.h"
#define MAX_PATIENTS 10
//const int PASSENGER_CAR_SEATS = 20;

struct patient_s {
    //patient_status_t status;
    char * name;
};

struct doctor_s {
    patient_t* patients[MAX_PATIENTS];
    char * name;
    int count;
};


patient_t * patient_new(char* name) {
    patient_t * self = malloc(sizeof(patient_t));
    //self->status = status;
    self->name = name;
    return self;
}
doctor_t * doctor_new(char* name) {
    doctor_t * self = malloc(sizeof(doctor_t));
   // self->status = status;
    //self->patients = list_new();
    self->name = name;
    self->count = 0;
    return self;
}
void patient_free(patient_t * self) {
    free(self);
}
void doctor_free(doctor_t * self) {
    free(self);
}

void patient_delete(clinic_t *clinic, patient_t * patient) {
     for (int i = 0; i < list_getSize(clinic->allpatients); i++) {
        patient_t * newpatient = (patient_t *)list_get(clinic->patients, i);
        if (newpatient == patient) {
            list_remove(clinic->allpatients, i);

            break;
        }

    }
    patient_free(patient);
}

void doctor_delete(clinic_t *clinic, doctor_t * doctor) {
     for (int i = 0; i < list_getSize(self->allpatients); i++) {
        doctor_t * newdoctor = (doctor_t *)list_get(clinic->alldoctors, i);
        if (newdoctor == doctor) {
            list_remove(clinic->alldoctors, i);
            break;
        }
    }
}
void doctor_addPatient(clinic_t clinic,doctor_t doctor, patient_t *patient)
{
    doctor->patients[count] = patient;
    count++;
}
void clinic_addPatient(clinic_t * self, patient_t * patient) {
    list_push_back(self->patients, patient);
}

void clinic_addDoctor(clinic_t * self, doctor_t * doctor) {
    list_push_back(self->doctors, doctor);
}
struct clinic_s {
   // clinic_status status;
    list_t * alldoctors;
    list_t * allpatients;
    char* name;
    subscriber_t *subscribers;
};

typedef struct subscriber_s {
    void * listener;
    start_fn callback;
} subscriber_t;

clinic_t * clinic_new() {
    clinic_t * self = malloc(sizeof(clinic_t));
    //self->status= CLINIC_FREE;
    self->alldoctors = list_new();
    self->allpatients = list_new();
    return self;
}

void clinic_free(clinic_t * self) {
    list_free(self->alldoctors);
    list_free(self->allpatients);
    free(self);
}

void doctor_subscribeStart(clinic_t * self, void * listener, start_fn callback) {
    subscriber_t * sub = malloc(sizeof(subscriber_t));
    sub->listener = listener;
    sub->callback = callback;
    list_push_back(self->subscribers, sub);
}
/*
void doctor_unsubscribeStart(clinic_t * self, void * listener, start_fn callback) {
    for (int i = 0; i < list_getSize(self->subscribers); i++) {
        subscriber_t * subs = (subscriber_t *)list_get(self->subscribers, i);
        if ((subs->listener == listener) && (subs->callback == callback)) {
            list_remove(self->subscribers, i);
            break;
        }
    }
}*/


