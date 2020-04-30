#include "exam.h"

#include<stdio.h>
#include<time.h>
#include "../util/util.h"

struct exam* init_exam(void){
    struct exam* new = (struct exam*)malloc(sizeof(struct exam));
    new->id = get_time();
    new->course_id = 0;
    strcpy(new->name, "");
    new->date_time = 0;
}

void print_exam(struct exam* e) {
    printf("Name    : %s\n", e->name);
    if(e->date_time){
    printf("Credits : %.1f\n", );
    }
}