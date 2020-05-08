#ifndef _COURSE_LIST_H
#define _COURSE_LIST_H

#include "course.h"

struct course_list_node {
    struct course *data;
    struct course_list_node *next;
};

struct course_list_node *init_course_list_node(struct course *data);
void free_course_list_node(struct course_list_node *node);

struct course_list {
    struct course_list_node *head;
    unsigned int size;
};

extern struct course_list *course_list;

void init_course_list();
void load_course_list();
int is_unique_course_list(struct course *data);
void insert_course_list(struct course *data);
void save_course_list();
void free_course_list();
void delete_in_course_list(char *code);

#endif