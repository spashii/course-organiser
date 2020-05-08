#ifndef _EXAM_H_
#define _EXAM_H_

#include <time.h>
#include "course.h"

enum exam_field_name{
    EXAM_ID,
    EXAM_COURSE_ID,
    EXAM_NAME,
    EXAM_DATETIME,
};

struct exam {
    long id;
    long course_id;
    char name[16];
    char details[128];
    time_t datetime;
};

struct exam *init_exam(struct course *c);
void print_exam(struct exam *e);

#endif

