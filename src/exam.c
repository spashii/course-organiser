#include "exam.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "course.h"
#include "course_index.h"
#include "util.h"

int sorted_by_course_index;

struct exam *init_exam(struct course *c) {
    struct exam *new = malloc(sizeof(struct exam));
    new->id = get_time();
    if (c) {
        new->course_id = c->id;
    }
    strncpy(new->name, "", 64);
    strncpy(new->details, "", 128);
    strncpy(new->location, "", 32);
    new->datetime = 0;
    return new;
}

struct exam *init_exam_by_course_code(char *code) {
    struct course *c = get_by_code_course_index(code);
    if (c) {
        return init_exam(c);
    }
    return NULL;
}

void print_exam(struct exam *e) {
    if (e) {
        printf("\nID       : %ld\n", e->id);
        printf("C_ID     : %ld\n", e->course_id);
        struct course *c = init_course();
        c = get_by_id_course_index(e->course_id);
        if (c) {
            printf("C_Code   : %s\n", c->code);
        }
        printf("Name     : %s\n", e->name);
        printf("Details  : %s\n", e->details);
        printf("Location : %s\n", e->location);
        printf("Time     : %s\n",
               get_datetime_format(e->datetime, "%d/%m/%Y %I:%M%p"));
    }
}

struct exam *set_exam(struct exam *e, char name[], char details[],
                      char location[], time_t datetime) {
    strncpy(e->name, xstrupr(name), 64);
    strncpy(e->details, xstrupr(details), 128);
    strncpy(e->location, xstrupr(location), 32);
    e->datetime = datetime;
    return e;
}

struct exam *input_exam(struct exam *e) {
    printf("Exam Name? ");
    char *name = s_readline(64);
    printf("Exam Details? ");
    char *details = s_readline(128);
    printf("Exam Location? ");
    char *location = s_readline(32);
    time_t datetime = input_time();
    e = set_exam(e, name, details, location, datetime);
    free(name);
    free(details);
    free(location);
    return e;
}

void *get_comparator_exam(enum exam_field_name f) {
    switch (f) {
        case EXAM_ID:
            return &compare_exam_id;
        case EXAM_COURSE_ID:
            return &compare_exam_course_id;
        case EXAM_NAME:
            return &compare_exam_name;
        case EXAM_DETAILS:
            return &compare_exam_details;
        case EXAM_LOCATION:
            return &compare_exam_location;
        case EXAM_DATETIME:
            return &compare_exam_datetime;
        default:
            return &compare_exam_course_id;
    }
}

int compare_exam_id(const void *a, const void *b) { return 0; }
int compare_exam_course_id(const void *a, const void *b) { return 0; }
int compare_exam_name(const void *a, const void *b) { return 0; }
int compare_exam_details(const void *a, const void *b) { return 0; }
int compare_exam_location(const void *a, const void *b) { return 0; }
int compare_exam_datetime(const void *a, const void *b) { return 0; }