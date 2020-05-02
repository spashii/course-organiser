#include "course_index.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "../course/course.h"
#include "../course_list/course_list.h"

void **course_index;
int course_index_size;

void init_course_index(struct course_list *l) {
    course_index = malloc(sizeof(struct course *) * (l->size));
    course_index_size = l->size;
}

void make_course_index(struct course_list *l) {
    init_course_index(l);
    int i = 0;
    struct course_list_node *trav = l->head;
    for (i = 0; i < l->size; i++) {
        course_index[i] = trav->data;
        trav = trav->next;
    }
}

void sort_course_index(enum sort_by sort_by_this) {
    if (course_index) {
        int size = course_index_size;
        switch (sort_by_this) {
            case COURSE_NAME:
                qsort(course_index, size, sizeof(struct course *), compare_course_name);
                break;
            case COURSE_CREDIT:
                qsort(course_index, size, sizeof(struct course *), compare_course_credit);
                break;
            case COURSE_CODE:
            default:
                qsort(course_index, size, sizeof(struct course *), compare_course_code);
        }
    }
}