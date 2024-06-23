#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100

struct patient {
    char patient_id[4];
    int critical_level;
    char time[6];
    bool isSpecialCase;
};

struct patient data[max];
int patient_index = 0;
int treat_index = 0;

void treatPatient() {
    if (patient_index == 0) {
        printf("No patients to treat.\n");
        return;
    }
    
    char *el = data[treat_index].patient_id;
    printf("%s is treated\n", el);
    
    for (int i = treat_index; i < patient_index - 1; i++) {
        data[i] = data[i + 1];
    }
    patient_index--;
}

void peekPatient() {
    if (treat_index + 1 < patient_index) {
        printf("Next patient is: %s\n", data[treat_index + 1].patient_id);
    } else {
        printf("No next patient.\n");
    }
}

void removePatient(char *patient_id) {
    for (int i = 0; i < patient_index; i++) {
        if (strcmp(patient_id, data[i].patient_id) == 0) {
            for (int j = i; j < patient_index - 1; j++) {
                data[j] = data[j + 1];
            }
            patient_index--;
            return;
        }
    }
    printf("Patient %s not found.\n", patient_id);
}

void addPatient(char *patient_id, int critical_level, char *time, bool isSpecialCase) {
    struct patient *x = (struct patient *) malloc(sizeof(struct patient));

    strcpy(x->patient_id, patient_id);
    x->critical_level = critical_level;
    strcpy(x->time, time);
    x->isSpecialCase = isSpecialCase;

    int np_hour, np_minute, op_hour, op_minute;

    int isBelow = 0;

    if (isSpecialCase) {
        int i = 0;
        while (i <= patient_index) {
            if ((data[i].isSpecialCase && critical_level > data[i].critical_level) || (!data[i].isSpecialCase)) {
                int j = patient_index;
                while (j > i) {
                    data[j] = data[j - 1];
                    j--;
                }
                data[i] = *x;
                free(x);
                isBelow++;
                patient_index++;
                return;
            } else if (!data[i + 1].isSpecialCase && critical_level <= data[i].critical_level) {
                int j = patient_index;
                while (j > i + 1) {
                    data[j] = data[j - 1];
                    j--;
                }
                data[i + 1] = *x;
                free(x);
                patient_index++;
                isBelow++;
                return;
            } else {
                i++;
            }
        }
    } else {
        if (patient_index > 0) {
            int i = 0;
            while (i <= patient_index) {
                if (critical_level > data[i].critical_level && data[i].isSpecialCase == false) {
                    int j = patient_index;
                    while (j > i) {
                        data[j] = data[j - 1];
                        j--;
                    }
                    data[i] = *x;
                    free(x);
                    patient_index++;
                    isBelow++;
                    return;
                } else if (critical_level == data[i].critical_level && data[i].isSpecialCase == false) {
                    char np_time[6], op_time[6];
                    strcpy(np_time, time);
                    strcpy(op_time, data[i].time);
                    np_hour = atoi(strtok(np_time, ":"));
                    np_minute = atoi(strtok(NULL, ":"));
                    op_hour = atoi(strtok(op_time, ":"));
                    op_minute = atoi(strtok(NULL, ":"));

                    if (op_hour == np_hour && op_minute < np_minute) {
                        data[patient_index] = *x;
                        free(x);
                        patient_index++;
                        isBelow++;
                        return;
                    } else if ((op_hour > np_hour) || ((op_hour == np_hour) && (op_minute > np_minute))) {
                        int j = patient_index;
                        while (j > i) {
                            data[j] = data[j - 1];
                            j--;
                        }
                        data[i] = *x;
                        free(x);
                        patient_index++;
                        isBelow++;
                        return;
                    }
                } else {
                    i++;
                }
            }
        }
    }

    if (isBelow == 0) {
        data[patient_index] = *x;
        free(x);
        patient_index++;
    }
}

int main() {
    addPatient("P1", 3, "09:00", false);
    addPatient("P2", 5, "09:05", false);
    addPatient("P3", 2, "09:10", false);
    addPatient("P4", 4, "09:15", true);

    printf("Patients in the queue:\n");
    for (int i = 0; i < patient_index; i++) {
        printf("%s\n", data[i].patient_id);
    }
	
	printf("\n");
	

    treatPatient();
    printf("\nAfter treating a patient:\n");
    for (int i = 0; i < patient_index; i++) {
        printf("%s\n", data[i].patient_id);
    }
	printf("\n");
    removePatient("P3");
    printf("\nAfter removing patient P3:\n");
    for (int i = 0; i < patient_index; i++) {
        printf("%s\n", data[i].patient_id);
    }

    return 0;
}

