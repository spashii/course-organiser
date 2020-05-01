#include "course_list.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../course/course.h"

struct course_list_node *init_course_list_node(struct course *data) {
    struct course_list_node *new = (struct course_list_node *)malloc(sizeof(struct course_list_node));
    new->data = init_course();
    if(data)
        memcpy(new->data, data, sizeof(struct course));
    new->next = NULL;
    return new;
}

struct course_list *init_course_list() {
    struct course_list *new = (struct course_list *)malloc(sizeof(struct course_list));
    new->head = NULL;
    new->size = 0;
    return new;
}

void insert_course_list(struct course_list *l, struct course *data) {
    struct course_list_node *insert = init_course_list_node(data);
    struct course_list_node *save = l->head;
    insert->next = save;
    l->head = insert;
    l->size += 1;
}
