#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    "specification.h"


static int    cur_person_id = 0;


void update_person_age(person_T *person) {
    int    cur_value;

    cur_value = person->age;
    person->age = cur_value + 1;

    return;
}

void update_person_health_state(person_T *person, bool increase, int value) {
    int    cur_value;

    if (increase == TRUE) {
        cur_value = person->health_state + value;
    } else {
        cur_value = person->health_state - value;
    }

    if (cur_value > CHEERFULNESS_MAX_VALUE) {
        person->health_state = CHEERFULNESS_MAX_VALUE;
        printf("INFO: Maximum CHEERFULNESS!");
    } else if (cur_value < CHEERFULNESS_MIN_VALUE) {
        person->health_state = CHEERFULNESS_MIN_VALUE;
        printf("INFO: Minimum CHEERFULNESS!");
    } else {
        person->health_state = cur_value;
    }
    return;
}

void update_person_emotional_state(person_T *person, bool increase, int value) {
    int    cur_value;

    if (increase == TRUE) {
        cur_value = person->emotional_state + value;
    } else {
        cur_value = person->emotional_state - value;
    }

    if (cur_value > CHEERFULNESS_MAX_VALUE) {
        person->emotional_state = CHEERFULNESS_MAX_VALUE;
        printf("INFO: Maximum CHEERFULNESS!");
    } else if (cur_value < CHEERFULNESS_MIN_VALUE) {
        person->emotional_state = CHEERFULNESS_MIN_VALUE;
        printf("INFO: Minimum CHEERFULNESS!");
    } else {
        person->emotional_state = cur_value;
    }

    return;
}

void update_person_environmental_satisfaction_state(person_T *person, bool increase, int value) {
    int    cur_value;

    if (increase == TRUE) {
        cur_value = person->environmental_satisfaction_state + value;
    } else {
        cur_value = person->environmental_satisfaction_state - value;
    }

    if (cur_value > ENVIRONMENTAL_SATISFACTION_MAX_VALUE) {
        person->environmental_satisfaction_state = ENVIRONMENTAL_SATISFACTION_MAX_VALUE;
        printf("INFO: Maximum ENVIRONMENTAL SATISFACTION!");
    } else if (cur_value < ENVIRONMENTAL_SATISFACTION_MIN_VALUE) {
        person->environmental_satisfaction_state = ENVIRONMENTAL_SATISFACTION_MIN_VALUE;
        printf("INFO: Minimum ENVIRONMENTAL SATISFACTION!");
        update_person_emotional_state(person, FALSE, value / 10);
    } else {
        person->environmental_satisfaction_state = cur_value;
    }

    return;
}

void update_person_satiety_state(person_T *person, bool increase, int value) {
    int    cur_value;

    if (increase == TRUE) {
        cur_value = person->satiety_state + value;
    } else {
        cur_value = person->satiety_state - value;
    }

    if (cur_value > SATIETY_MAX_VALUE) {
        person->satiety_state = SATIETY_MAX_VALUE;
        printf("INFO: Maximum SATIETY!");
    } else if (cur_value < SATIETY_MIN_VALUE) {
        person->satiety_state = SATIETY_MIN_VALUE;
        printf("INFO: Minimum SATIETY!");
        update_person_emotional_state(person, FALSE, value / 10);
        update_person_health_state(person, FALSE, value / 10);
    } else {
        person->satiety_state = cur_value;
    }

    return;
}

void update_person_cheerfulness_state(person_T *person, bool increase, int value) {
    int    cur_value;

    if (increase == TRUE) {
        cur_value = person->cheerfulness_state + value;
    } else {
        cur_value = person->cheerfulness_state - value;
    }

    if (cur_value > CHEERFULNESS_MAX_VALUE) {
        person->cheerfulness_state = CHEERFULNESS_MAX_VALUE;
        printf("INFO: Maximum CHEERFULNESS!");
    } else if (cur_value < CHEERFULNESS_MIN_VALUE) {
        person->cheerfulness_state = CHEERFULNESS_MIN_VALUE;
        printf("INFO: Minimum CHEERFULNESS!");
        update_person_emotional_state(person, FALSE, value / 10);
        update_person_health_state(person, FALSE, value / 10);
    } else {
        person->cheerfulness_state = cur_value;
    }

    return;
}

int alloc_person_id() {
    cur_person_id++;

    return cur_person_id;
}

extern void generete_person(person_T *person, char *name) {
    int    name_len = 0;

    memset(person, 0, sizeof(person_T));
    person->id = alloc_person_id();
    name_len = strlen(name);
    if (name_len > NAME_MAX_LEN) {
        name_len = NAME_MAX_LEN;
        printf("WARNING: Person name too long.\n");
    }
    strncpy(person->name, name, name_len);
    person->sex        = rand()%(NO_SEX + 1);
    person->eyes_color = rand()%(UNKNOWN_COLOR + 1);
    person->hair_color = rand()%(UNKNOWN_COLOR + 1);
    person->body_type  = rand()%(ALIEN_BODY + 1);
    person->brain_type = rand()%(NO_BRAIN + 1);
    person->age        = 0;
    if (0 /* is_your_mom_smoker */) {
        person->health_state                 = HEALTH_MAX_VALUE - (HEALTH_MAX_VALUE / 10);
    } else {
        person->health_state                 = HEALTH_MAX_VALUE;
    }
    person->emotional_state                  = EMOTIONAL_MAX_VALUE;
    person->environmental_satisfaction_state = ENVIRONMENTAL_SATISFACTION_MAX_VALUE;
    person->satiety_state                    = SATIETY_MAX_VALUE / 2;
    if (1 /* is_cur_time_am */) {
        person->cheerfulness_state           = CHEERFULNESS_MAX_VALUE;
    } else {
        person->cheerfulness_state           = CHEERFULNESS_MAX_VALUE / 2;
    }

    return;
}

extern void show_person_specification(person_T *person) {
    printf("Person: ID: %d, NAME: %s, SEX: %d\n"
           "EYES: %d, HAIR: %d, BODY: %d, BRAIN: %d\n"
           "AGE: %d, HEALTH: %d, EMO: %d, ENV: %d, EAT: %d SLEEP: %d\n",
    person->id,
    person->name,
    person->sex,
    person->eyes_color,
    person->hair_color,
    person->body_type,
    person->brain_type,
    person->age,
    person->health_state,
    person->emotional_state,
    person->environmental_satisfaction_state,
    person->satiety_state,
    person->cheerfulness_state);

    return;
}


