#include "course_index.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "course.h"
#include "course_list.h"

void **course_index;
int course_index_size;
struct course_list *course_list;

void init_course_index() {
    course_index = malloc(sizeof(struct course *) * (course_list->size));
    course_index_size = course_list->size;
}

void make_course_index() {
    init_course_index();
    int i = 0;
    struct course_list_node *trav = course_list->head;
    for (i = 0; i < course_list->size; i++) {
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