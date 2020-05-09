#ifndef _EXAM_H_
#define _EXAM_H_

#include <time.h>
#include "course.h"

enum exam_field_name {
    EXAM_ID,
    EXAM_COURSE_ID,
    EXAM_NAME,
    EXAM_DETAILS,
    EXAM_LOCATION,
    EXAM_DATETIME,
};

struct exam {
    long id;
    long course_id;
    char name[16];
    char details[128];
    char location[16];
    time_t datetime;
};

struct exam *init_exam(struct course *c);
struct exam *init_exam_by_course_code(char *code);
void print_exam(struct exam *e);
void print_short_exam(struct exam *e);
struct exam *set_exam(struct exam *e, char name[], char details[], char location[], time_t datetime);
struct exam *input_exam(struct exam *e);
char *get_course_code_exam(struct exam *e);
int is_active_exam(struct exam *e);

void *get_comparator_exam(enum exam_field_name f);

int compare_exam_id(const void *a, const void *b);
int compare_exam_course_id(const void *a, const void *b);
int compare_exam_name(const void *a, const void *b);
int compare_exam_details(const void *a, const void *b);
int compare_exam_location(const void *a, const void *b);
int compare_exam_datetime(const void *a, const void *b);


#endif

