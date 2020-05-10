#include "exam.h"

#include <stdlib.h>
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
    strncpy(new->name, "", 16);
    strncpy(new->details, "", 128);
    strncpy(new->location, "", 16);
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
        printf("---------------------------------------------------\n");
        printf("|NAME           | %-32s|\n", e->name);
        printf("|COURSE CODE    | %-32s|\n", get_course_code_exam(e));
        printf("|DATE           | %-32s|\n",
               get_datetime_format(e->datetime, "%a %b %d %G"));
        printf("|TIME           | %-32s|\n",
               get_datetime_format(e->datetime, "%I:%M%p"));
        printf("|LOCATION       | %-32s|\n", e->location);
        printf("|STATUS         | %-32s|\n",
               is_active_exam(e) ? "ACTIVE" : "INACTIVE");
        printf("---------------------------------------------------\n");

        printf("\nEXAM DETAILS : %s\n", e->details);
    }
}

void print_short_exam(struct exam *e) {
    if (e) {
        printf("| %-16s on %-13s at %-16s |\n", e->name,
               get_datetime_format(e->datetime, "%d/%m %I:%M%p"), e->location);
    }
}

struct exam *set_exam(struct exam *e, char name[], char details[],
                      char location[], time_t datetime) {
    strncpy(e->name, xstrupr(name), 16);
    strncpy(e->details, xstrupr(details), 128);
    strncpy(e->location, xstrupr(location), 16);
    e->datetime = datetime;
    return e;
}

struct exam *input_exam(struct exam *e) {
    printf("Exam Name? ");
    char *name = s_readline(16);
    printf("Exam Details? ");
    char *details = s_readline(128);
    printf("Exam Location? ");
    char *location = s_readline(16);
    time_t datetime = input_time();
    e = set_exam(e, name, details, location, datetime);
    free(name);
    free(details);
    free(location);
    return e;
}

char *get_course_code_exam(struct exam *e) {
    if (e) {
        struct course *c = get_by_id_course_index(e->course_id);
        if (c) {
            return c->code;
        }
    }
    return NULL;
}

int is_active_exam(struct exam *e) {
    if (e) {
        if (e->datetime > get_time()) {
            return 1;
        }
    }
    return 0;
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

int compare_exam_id(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return (int)(left->id - right->id);
}

int compare_exam_course_id(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return (int)(left->course_id - right->course_id);
}

int compare_exam_name(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return strncmp(left->name, right->name, 64);
}

int compare_exam_details(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return strncmp(left->details, right->details, 128);
}

int compare_exam_location(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return strncmp(left->location, right->location, 32);
}

int compare_exam_datetime(const void *a, const void *b) {
    struct exam *left = *(struct exam **)a;
    struct exam *right = *(struct exam **)b;
    return (int)(left->datetime - right->datetime);
}