#ifndef _COURSE_INDEX_H_
#define _COURSE_INDEX_H_

#include "course.h"
#include "course_list.h"

struct course_index {
    // an array of void pointers which we
    // will use to store struct course ptrs
    void **c;
    unsigned int size;
};

extern struct course_index *course_index;

enum sort_by {
    COURSE_CODE,
    COURSE_NAME,
    COURSE_CREDIT
};

void init_course_index();
void load_course_index();
void sort_course_index(enum sort_by field_name);
void free_course_index();

void make_course_index(enum sort_by field_name);

int get_size_course_index();

#endif