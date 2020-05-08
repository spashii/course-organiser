#include "exam_operation.h"

#include <stdio.h>

#include "exam.h"
#include "exam_index.h"
#include "exam_list.h"
#include "util.h"

void init_exam_operation() {
    load_exam_list();
    make_exam_index(EXAM_DATETIME);
}

void display_code_name_date_exam_operation() {
    int i;
    for (i = 0; i < exam_index->size; i++) {
        printf("%2d. %10s - %s\n", i + 1,
               get_course_code_exam(exam_index->c[i]),
               get_datetime_format(exam_index->c[i]->datetime,
                                   "%d/%m/%Y %I:%M%p"));
    }
}

void delete_exam_operation(struct exam *e) {
    delete_in_exam_list(e->id);
    make_exam_index(EXAM_DATETIME);
}

void save_exam_operation() {
    save_exam_list();
    free_exam_list();
}