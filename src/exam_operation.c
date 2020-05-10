#include "exam_operation.h"

#include <stdio.h>
//#include <malloc.h>

#include "course_index.h"
#include "exam.h"
#include "exam_index.h"
#include "exam_list.h"
#include "util.h"

void init_exam_operation() {
    printf("Loading exams....\n");
    load_exam_list();
    make_exam_index(EXAM_DATETIME);
}

void display_code_name_date_exam_operation() {
    int i;
    struct exam *e;
    printf(
        "---------------------------------------------------------\n");
    printf("| %-2s | %-16s | %-16s | %-10s |\n", "NO", "COURSE CODE", "EXAM",
           "DATE");
    printf("---------------------------------------------------------\n");
    for (i = 0; i < exam_index->size; i++) {
        e = exam_index->e[i];
        if (e->course_id)
            printf("| %-2d | %-16s | %-16s | %-10s |\n", i + 1,
                   get_course_code_exam(e), e->name,
                   get_datetime_format(e->datetime, "%d/%m/%Y"));
    }
    printf("---------------------------------------------------------\n");
}

void delete_exam_operation(struct exam *e) {
    delete_in_exam_list(e->id);
    make_exam_index(EXAM_DATETIME);
}

void edit_exam_operation(struct exam *e) {
    long course_id = e->course_id;
    struct course* temp = init_course();
    temp->id = course_id;
    struct exam *new = input_exam(init_exam(temp));
    delete_in_exam_list(e->id);
    while (!is_unique_exam_list(new)) {
        printf("\nEnter exam details again:\n");
        new = input_exam(new);
    }
    insert_exam_list(new);
    make_exam_index(EXAM_DATETIME);
    free(temp);
}

void insert_exam_operation(struct course *c) {
    nl();
    struct exam *new = input_exam(init_exam(c));
    while (!is_unique_exam_list(new)) {
        printf("\nEnter exam details again:\n");
        new = input_exam(new);
    }
    insert_exam_list(new);
    make_exam_index(EXAM_DATETIME);
}

void save_exam_operation() {
    save_exam_list();
    free_exam_list();
}