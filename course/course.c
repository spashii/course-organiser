#include "course.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../util/util.h"

struct course* init_course(void) {
    struct course* new = (struct course*)malloc(sizeof(struct course));
    strcpy(new->code, "");
    strcpy(new->name, "");
    new->credit = 0.0;
    return new;
}

void print_course(struct course* foo) {
    printf("Code    : %s\n", foo->code);
    printf("Name    : %s\n", foo->name);
    printf("Credits : %.1f\n", foo->credit);
}

void set_course(struct course* foo, char code[], char name[], float credit) {
    strcpy(foo->code, code);
    strcpy(foo->name, name);
    foo->credit = credit;
}

struct course* input_course(struct course* foo) {
    char code[16];
    char name[64];
    float credit;
    printf("Course Code? ");
    strcpy(code, s_readline(16));
    printf("Course Name? ");
    strcpy(name, s_readline(64));
    printf("Course Credits? ");
    scanf("%f", &credit);
    set_course(foo, code, name, credit);
    return foo;
}