#include "course.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../util/util.h"

struct course* init_course(void) {
    struct course* new = (struct course*)malloc(sizeof(struct course));
    new->id = get_time();
    strcpy(new->code, "");
    strcpy(new->name, "");
    new->credit = 0.0;
    return new;
}

void print_course(struct course* c) {
    printf("Code    : %s\n", c->code);
    printf("Name    : %s\n", c->name);
    printf("Credits : %.1f\n", c->credit);
}

void set_course(struct course* c, char code[], char name[], float credit) {
    strcpy(c->code, code);
    strcpy(c->name, name);
    c->credit = credit;
}

struct course* input_course(struct course* c) {
    char code[16];
    char name[64];
    float credit;
    printf("Course Code? ");
    strcpy(code, s_readline(16));
    printf("Course Name? ");
    strcpy(name, s_readline(64));
    printf("Course Credits? ");
    scanf("%f", &credit);
    set_course(c, code, name, credit);
    return c;
}