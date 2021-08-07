#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <pthread.h>
#include    <string.h>

#include    "pet.h"
#include    "specification/specification.h"
#include    "environment/environment.h"


int           DEBUG_ON = 0;


void *word_tic(void *arg) {
    while (1) {
        if (DEBUG_ON) {
            printf("word_tic: loop\n");
        }
        sleep(1);
        time_update();
    }
}

void *main_menu(void *arg) {
    person_T    person;
    char        person_name[NAME_MAX_LEN];
    char        manu_option[3];
    menu_T      menu;

    printf("Welcome to pet.\nEnter person name: ");
    scanf("%s", person_name);

    generete_person(&person, person_name);
    show_person_specification(&person);
    while (1) {
        if (DEBUG_ON) {
            printf("main_menu: loop\n");
        }
        sleep(1);

        scanf("%s", person_name);
    }

    /*
    while (1) {
        if (!DEBUG_ON) {
            printf("\033c");
        }

        printf("\n");
        printf(" / \\ _ / \\  \n");
        printf("(  o . o  ) \n");
        printf("  >  ^  <   \n");
        sleep(1);
        printf("\033c");

        printf("\n");
        printf("  ^  _ / \\  \n");
        printf("( o . o   ) \n");
        printf("  >  ^  <   \n");
        sleep(1);
        printf("\033c");

        if () {
            break;
        }
    }
    show_person_specification(&person);
    */
}

int main(int argc, char** argv) {
    int                     i;
    int                     debug = 1;
    thread_description_T    thread[MAX_THREAD];

    if (argc > 1) {
        debug = !(strcmp("-d", argv[1]));
        DEBUG_ON = debug;
    }

    memset(thread, 0, MAX_THREAD * sizeof(thread_description_T));

    thread[MAIN_MENU_THREAD].func = main_menu;
    thread[WORD_TIC_THREAD].func = word_tic;

    for (i = 0; i < MAX_THREAD; i++) {
        thread[i].id = i;
        pthread_attr_init(&thread[i].attr);
        pthread_create(&thread[i].thread, &thread[i].attr, thread[i].func, thread[i].arg);
        printf("Create thread: id: %d\n", i);
    }
    pthread_join(thread[MAIN_MENU_THREAD].thread, NULL);

    return 0;
}


