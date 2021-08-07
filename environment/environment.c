//#include    "specification/specification.h"
#include    "environment.h"


static int    cur_year = 0;
static int    cur_day  = 0;
static int    cur_hour = 0;


void go_eat() {

    return;
}

void go_sleep() {

    return;
}

void update_cur_location() {

    return;
}

void update_cur_year() {
    cur_year++;
    return;
}

void update_cur_day() {
    cur_day++;
    if (cur_day == CUR_DAY_MAX_VALUE) {
        cur_day = CUR_DAY_MIN_VALUE;
        update_cur_year();
    }

    return;
}

extern void time_update() {
    cur_hour++;
    if (cur_hour == CUR_HOUR_MAX_VALUE) {
        cur_hour = CUR_HOUR_MIN_VALUE;
        update_cur_day();
    }
    if (cur_hour == CUR_HOUR_MIN_VALUE) {

    }

    return;
}


