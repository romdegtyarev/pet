#ifndef SPECIFICATION_H_
#define SPECIFICATION_H_


#define NAME_MAX_LEN                            256

#define HEALTH_MIN_VALUE                        0
#define EMOTIONAL_MIN_VALUE                     0
#define ENVIRONMENTAL_SATISFACTION_MIN_VALUE    0
#define SATIETY_MIN_VALUE                       0
#define CHEERFULNESS_MIN_VALUE                  0

#define HEALTH_MAX_VALUE                        100
#define EMOTIONAL_MAX_VALUE                     100
#define ENVIRONMENTAL_SATISFACTION_MAX_VALUE    100
#define SATIETY_MAX_VALUE                       100
#define CHEERFULNESS_MAX_VALUE                  100


typedef enum {
    FALSE,
    TRUE
} bool;

typedef enum color {
    BLACK,
    WHITE,
    PURPLE,
    BLUE,
    GREEN,
    YELLOW,
    ORANGE,
    RED,
    BROWN,
    UNKNOWN_COLOR
} color_T;

typedef enum sex {
    MALE,
    FEMALE,
    NO_SEX
} sex_T;

typedef enum body_type {
    EXTRA_SLIM,
    SLIM,
    AVAGE_BODY,
    FIT,
    EXTRA_FIT,
    FAT,
    INVALID,
    ALIEN_BODY
} body_type_T;

typedef enum brain_type {
    EXTRA_STUPIDE,
    STUPIDE,
    AVAGE_BRAIN,
    SMART,
    EXTRA_SMART,
    NO_BRAIN
} brain_type_T;


typedef struct person {
    int             id;
    char            name[NAME_MAX_LEN];
    sex_T           sex;
    color_T         eyes_color;
    color_T         hair_color;
    body_type_T     body_type;
    brain_type_T    brain_type;
    int             age;
    int             health_state;
    int             emotional_state;
    int             environmental_satisfaction_state;
    int             satiety_state;
    int             cheerfulness_state;
} person_T;


extern void generete_person(person_T *person, char *name);
extern void show_person_specification(person_T *person);


#endif /* SPECIFICATION_H_ */


