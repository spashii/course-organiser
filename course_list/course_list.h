#ifndef _COURSE_LIST_H
#define _COURSE_LIST_H

#include "../course/course.h"

struct course_list_node {
    struct course *data;
    struct course_list_node *next;
};

struct course_list_node *init_course_list_node(struct course *data);

struct course_list{
    struct course_list_node *head;
};

struct course_list *init_course_list();
void insert_course_list(struct course_list *l, struct course *data);

#endif