#ifndef _COURSE_INDEX_H_
#define _COURSE_INDEX_H_

#include "course.h"
#include "course_list.h"

// an array of void pointers which we
// will use to store struct course ptrs
extern void **course_index;
extern int course_index_size;

enum sort_by {
    COURSE_CODE,
    COURSE_NAME,
    COURSE_CREDIT
};

void init_course_index(struct course_list *l);
void make_course_index(struct course_list *l);
void sort_course_index(enum sort_by sort_by_this);

int get_size_course_index();

#endif