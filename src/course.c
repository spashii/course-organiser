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
    strncpy(new->name, "", 128);
    strncpy(new->dept,"",128);
    strncpy(new->room,"",16);
    strncpy(new->type,"",128);
    new->credit = 0.0;
    return new;
}

void print_course(struct course *c) {
    printf("\nID      : %ld\n", c->id);
    printf("Code    : %s\n", c->code);
    printf("Name    : %s\n", c->name);
    printf("Credits : %.1f\n", c->credit);
    printf("Department   : %s\n", c->dept);
    printf("Room    : %s\n", c->room);
    printf("Type    : %s\n", c->type);
}

struct course *set_course(struct course *c, char code[], char name[], float credit,char dept[],char room[], char type[]) {
    strncpy(c->code, code, 16);
    strncpy(c->name, name, 128);
    c->credit = credit;
    strncpy(c->dept, dept, 128);
    strncpy(c->room, room, 16);
    strncpy(c->type, type, 128);
    return c;
}

struct course *input_course(struct course *c) {
    printf("Course Code? ");
    char *code = s_readline(16);
    printf("Course Name? ");
    char *name = s_readline(128);
    printf("Course Credits? ");
    float credit;
    scanf("%f", &credit);
    printf("Course Department? ");
    char *dept = s_readline(128);
    printf("Course Room? ")'
    char *room = s_readline(16);
    printf("Course Type?");
    char *type =s_readline(128);
    flush_stdin_buffer();
    set_course(c, code, name, credit, dept, room, type);
    free(name);
    free(code);
    free(dept);
    free(room);
    free(type);
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

int compare_course_code(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;
    return strcmp(left->code, right->code);
}

int compare_course_name(const void *a, const void *b) {
    struct course *left = *(struct course **)a;
    struct course *right = *(struct course **)b;
    return strcmp(left->name, right->name);
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
