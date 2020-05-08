#ifndef _EXAM_LIST_H
#define _EXAM_LIST_H

#include "exam.h"

struct exam_list_node {
    struct exam *data;
    struct exam_list_node *next;
};

struct exam_list_node *init_exam_list_node(struct exam *data);
void free_exam_list_node(struct exam_list_node *node);

struct exam_list {
    struct exam_list_node *head;
    unsigned int size;
};

extern struct exam_list *exam_list;

void init_exam_list();
void load_exam_list();
int is_unique_exam_list(struct exam *data);
void insert_exam_list(struct exam *data);
void save_exam_list();
void free_exam_list();
void delete_in_exam_list(long id);

#endif