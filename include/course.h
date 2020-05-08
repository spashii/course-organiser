#ifndef _COURSE_H_
#define _COURSE_H_

enum course_field_name { 
    COURSE_ID,
    COURSE_CODE, 
    COURSE_NAME, 
    COURSE_CREDIT 
};

struct course {
    long id;
    char code[16];
    char name[128];
    float credit;
};

// initializes a course object
struct course *init_course(void);

// prints a course object
void print_course(struct course *c);

// course object setter
struct course *set_course(struct course *c, char code[], char name[],
                          float credit);

// set_course() wrapper
struct course *input_course(struct course *c);

// comparing functions
void *get_comparator_course(enum course_field_name f);
int compare_course_id(const void *a, const void *b);
int compare_course_code(const void *a, const void *b);
int compare_course_name(const void *a, const void *b);
int compare_course_credit(const void *a, const void *b);

// *TESTING*
// inserts course record into course.db
int insert_course_db(struct course *record);

#endif
