#include "course_operation.h"

#include <stdio.h>

#include "course.h"
#include "course_index.h"
#include "course_list.h"
#include "exam_index.h"
#include "exam_list.h"
#include "util.h"

void init_course_operation() {
    printf("Loading courses....\n");
    load_course_list();
    make_course_index(COURSE_CODE);
}

void display_code_name_course_operation() {
    int i;
    char is_active;
    struct course *c;
    printf("\nLIST OF ALL COURSES (* denotes exam active)\n\n");
    printf(
        "-----------------------------------------------------------------------"
        "---------------------\n");
    printf("| %-2s |  %-16s | %-64s |\n", "NO", "CODE", "NAME");
    printf(
        "-----------------------------------------------------------------------"
        "---------------------\n");

    for (i = 0; i < course_index->size; i++) {
        c = course_index->c[i];
        is_active = (count_course_exam_index(c) != 0) ? '*' : ' ';
        printf("| %-2d | %c%-16s | %-64s |\n", i + 1, is_active, c->code,
               c->name);
    }
    printf(
        "-----------------------------------------------------------------------"
        "---------------------\n");
}

void delete_course_operation(struct course *c) {
    delete_exams_of_course_exam_list(c->id);
    delete_in_course_list(c->code);
    make_course_index(COURSE_CODE);
    make_exam_index(EXAM_DATETIME);
}

void edit_course_operation(struct course *c) {
    struct course *new = input_course(init_course());
    long c_id = c->id;
    delete_in_course_list(c->code);
    while (!is_unique_course_list(new)) {
        printf("\nEnter course details again:\n");
        new = input_course(new);
    }
    // doesn't break exam foreign key
    new->id = c_id;
    insert_course_list(new);
    make_course_index(COURSE_CODE);
}

void insert_course_operation() {
    nl();
    struct course *new = input_course(init_course());
    while (!is_unique_course_list(new)) {
        printf("\nEnter course details again:\n");
        new = input_course(new);
    }
    insert_course_list(new);
    make_course_index(COURSE_CODE);
}

void save_course_operation() {
    save_course_list();
    free_course_index();
    free_course_list();
}

int search_course_operation(char *code_key) {
    return get_index_by_code_course_index(code_key);
}