#include "exam.h"

#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <string.h>

#include "course.h"
#include "course_index.h"
#include "util.h"

int sorted_by_course_index;

struct exam *init_exam(struct course* c){
    struct exam *new = malloc(sizeof(struct exam));
    new->id = get_time();
    new->course_id = c->id;
    strncpy(new->name, "test", 16);
    strncpy(new->details, "test", 128);
    new->datetime = 0;
    return new;
};

void print_exam(struct exam *e){
    printf("\nID      : %ld\n", e->id);
    printf("C_ID    : %ld\n", e->course_id);
    struct course *c = init_course();
    c = get_by_id_course_index(e->course_id);
    if(c) {
        printf("C_Code  : %s\n", c->code);
    }
    printf("Name    : %s\n", e->name);
    printf("Details : %s\n", e->details);
}
