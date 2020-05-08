#include "course_operation.h"

#include <stdio.h>

#include "course.h"
#include "course_index.h"
#include "util.h"

void init_course_operation(){
    load_course_list();
    make_course_index(COURSE_CODE);
}

void display_code_name_course_operation(){
    int i;
    for (i = 0; i < course_index->size; i++) {
        printf("%2d. %-16s - %s\n", i + 1, course_index->c[i]->code, course_index->c[i]->name);
    }
}

void delete_course_operation(struct course *c){
    delete_in_course_list(c->code);
    make_course_index(COURSE_CODE);
}

void edit_course_operation(struct course *c){
    struct course *new = input_course(init_course());
    long c_id = c->id;
    delete_in_course_list(c->code);
    while(!is_unique_course_list(new)) {
        printf("\nEnter course details again:\n");
        new = input_course(new);
    }
    // doesn't break exam foreign key
    new->id = c_id;
    insert_course_list(new);
    make_course_index(COURSE_CODE);
}

void insert_course_operation(){
    nl();
    struct course *new = input_course(init_course());
    while(!is_unique_course_list(new)) {
        printf("\nEnter course details again:\n");
        new = input_course(new);
    }
    insert_course_list(new);
    make_course_index(COURSE_CODE);
}

void save_course_operation(){
    save_course_list();
    free_course_index();
    free_course_list();
}
