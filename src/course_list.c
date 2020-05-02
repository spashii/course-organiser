#include "course_list.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "course.h"
#include "file.h"
#include "info.h"

struct course_list *course_list;

struct course_list_node *init_course_list_node(struct course *data) {
    struct course_list_node *new = malloc(sizeof(struct course_list_node));
    new->data = init_course();
    if (data)
        memcpy(new->data, data, sizeof(struct course));
    new->next = NULL;
    return new;
}

void free_course_list_node(struct course_list_node *node) {
    if (node) {
        free(node->data);
        free(node);
    }
    // free(node);
}

void init_course_list() {
    course_list = malloc(sizeof(struct course_list));
    course_list->head = NULL;
    course_list->size = 0;
}

void load_course_list() {
    init_course_list();
    FILE *db = open_db(COURSE_DB, READ);
    if (db && course_list) {
        init_info();
        struct course *temp = init_course();
        while (fread(temp, sizeof(struct course), 1, db)) {
            insert_course_list(temp);
            inc_course_count();
            memset(temp, 0, sizeof(struct course));
        }
        save_info();
        close_db(db);
    }
}

void insert_course_list(struct course *data) {
    struct course_list_node *insert = init_course_list_node(data);
    struct course_list_node *save = course_list->head;
    insert->next = save;
    course_list->head = insert;
    course_list->size += 1;
}

void save_course_list() {
    copy_db(COURSE_DB_BKP, COURSE_DB, OVERWRITE);
    FILE *db = open_db(COURSE_DB, OVERWRITE);
    if (db && course_list) {
        init_info();
        struct course_list_node *trav = course_list->head;
        while (trav) {
            if (fwrite(trav->data, sizeof(struct course), 1, db)) {
                trav = trav->next;
                inc_course_count();
            } else {
                break;
            }
        }
        save_info();
        close_db(db);
    }
}

void free_course_list() {
    if (course_list) {
        struct course_list_node *trav = course_list->head;
        struct course_list_node *trav_next;
        do {
            trav_next = trav->next;
            free_course_list_node(trav);
            trav = trav_next;
        } while (trav_next);
        free(course_list);
    }
}
