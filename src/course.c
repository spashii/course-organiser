#include "course.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "file.h"
#include "util.h"

struct course *init_course() {
    struct course *new = (struct course *)malloc(sizeof(struct course));
    new->id = get_time();
    strncpy(new->code, "", 16);
    strncpy(new->name, "", 64);
    new->credit = 0.0;
    return new;
}

void print_course(struct course *c) {
    if (c) {
        // printf("\nID      : %ld\n", c->id);
        printf(
            "------------------------------------------------------------------"
            "----------\n");
        printf("|CODE    | %-64s|\n", c->code);
        printf("|NAME    | %-64s|\n", c->name);
        printf("|CREDITS | %-64.1f|\n", c->credit);
        printf(
            "------------------------------------------------------------------"
            "----------");
    }
}

struct course *set_course(struct course *c, char code[], char name[],
                          float credit) {
    strncpy(c->code, xstrupr(code), 16);
    strncpy(c->name, xstrupr(name), 64);
    c->credit = credit;
    return c;
}

struct course *input_course(struct course *c) {
    printf("Course Code? ");
    char *code = s_readline(16);
    printf("Course Name? ");
    char *name = s_readline(64);
    printf("Course Credits? ");
    float credit;
    scanf("%f", &credit);
    flush_stdin_buffer();
    c = set_course(c, code, name, credit);
    free(name);
    free(code);
    return c;
}

int insert_course_db(struct course *record) {
    FILE *db = open_db(COURSE_DB, APPEND);
    if (db) {
        if (fwrite(record, sizeof(struct course), 1, db)) {
            close_db(db);
            return 1;
        }
        close_db(db);
        return 0;
    }
    return -1;
}

void *get_comparator_course(enum course_field_name f) {
    switch (f) {
        case COURSE_ID:
            return &compare_course_id;
        case COURSE_CODE:
            return &compare_course_code;
        case COURSE_NAME:
            return &compare_course_name;
        case COURSE_CREDIT:
            return &compare_course_credit;
        default:
            return &compare_course_code;
    }
}

int compare_course_id(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;
    return (int)(left->id - right->id);
}

int compare_course_code(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;

    return strncmp(left->code, right->code, 16);
}

int compare_course_name(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;
    return strncmp(left->name, right->name, 64);
}

int compare_course_credit(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;
    if (left->credit > right->credit) {
        return 1;
    } else if (left->credit < right->credit) {
        return -1;
    } else {
        return 0;
    }
}
