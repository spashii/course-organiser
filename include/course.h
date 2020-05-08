#ifndef _COURSE_H_
#define _COURSE_H_

struct course {
    long id;
    char code[16];
    char name[128];
    float credit;
    char dept[128];
    char room[16];
    char type[128];
};

// initializes a course object
struct course *init_course(void);

// course object setter
struct course *set_course(struct course *foo, char code[], char name[], float credit, char dept[], char room[], char type[]);

// set_course() wrapper
struct course *input_course(struct course *foo);

// prints a course object
void print_course(struct course *foo);

// comparing functions
int compare_course_code(const void *a, const void *b);
int compare_course_name(const void *a, const void *b);
int compare_course_credit(const void *a, const void *b);

// *TESTING* 
// inserts course record into course.db
int insert_course_db(struct course *record);

#endif

