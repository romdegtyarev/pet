#ifndef PET_H_
#define PET_H_


typedef enum menu {
    MAIN_MENU_THREAD,
    WORD_TIC_THREAD,
    MAX_THREAD
} menu_T;

typedef enum thread_num {
    MAIN_MENU_THREAD,
    WORD_TIC_THREAD,
    MAX_THREAD
} thread_num_T;


typedef struct thread_description {
    thread_num_T      id;
    pthread_t         thread;
    pthread_attr_t    attr;
    void             *func;
    void             *arg;
} thread_description_T;


#endif /* SPECIFICATION_H_ */


