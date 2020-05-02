#include "course_index.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "course.h"
#include "course_list.h"

struct course_index *course_index;
struct course_list *course_list;

void init_course_index() {
    if (course_list) {
        course_index = malloc(sizeof(struct course_index));
        course_index->c = malloc(sizeof(struct course *) * (course_list->size));
        course_index->size = course_list->size;
    }
}

void load_course_index() {
    int i = 0;
    struct course_list_node *trav = course_list->head;
    while(trav && i < course_index->size) {
        course_index->c[i++] = trav->data;
        trav = trav->next;
    }
}

void sort_course_index(enum sort_by field_name) {
    if (course_index) {
        switch (field_name) {
            case COURSE_NAME:
                qsort(course_index->c, course_index->size, sizeof(struct course *), compare_course_name);
                break;
            case COURSE_CREDIT:
                qsort(course_index->c, course_index->size, sizeof(struct course *), compare_course_credit);
                break;
            case COURSE_CODE:
            default:
                qsort(course_index->c, course_index->size, sizeof(struct course *), compare_course_code);
        }
    }
}

void free_course_index(){
    free(course_index->c);
    free(course_index);
}

void make_course_index(enum sort_by field_name){
    if(course_index){
        free(course_index);
    }
    init_course_index();
    load_course_index();
    sort_course_index(field_name);
}