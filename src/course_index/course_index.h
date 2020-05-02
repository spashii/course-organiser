#ifndef _COURSE_INDEX_H_
#define _COURSE_INDEX_H_

#include "../course/course.h"
#include "../course_list/course_list.h"

struct avl_tree_c {
    int size;
    int count;
    long (*cmp_c)(const void *c1, const void *c2);
    struct course **courses;
};

struct avl_tree_iter_c {
    int current_node;
};



#endif
