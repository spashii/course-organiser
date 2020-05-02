#ifndef _COURSE_LIST_H
#define _COURSE_LIST_H

#include "../course/course.h"

struct course_list_node {
    struct course *data;
    struct course_list_node *next;
};

struct course_list_node *init_course_list_node(struct course *data);

struct course_list {
    struct course_list_node *head;
    unsigned int size;
};

struct course_list *init_course_list();
void insert_course_list(struct course_list *l, struct course *data);

struct course_list *load_course_db();
void save_course_db(struct course_list *courses);

#endif