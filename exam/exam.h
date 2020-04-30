#ifndef _EXAM_H_
#define _EXAM_H_

#include<time.h>

struct exam{
    long id;
    long course_id;
    char name[64];
    time_t date_time;
};

struct exam* init_exam(void);
void print_exam(struct exam* foo);

#endif