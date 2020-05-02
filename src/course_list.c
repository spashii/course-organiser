#include "course_list.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "course.h"
#include "info.h"
#include "file.h"

struct course_list_node *init_course_list_node(struct course *data) {
    struct course_list_node *new = (struct course_list_node *)malloc(sizeof(struct course_list_node));
    new->data = init_course();
    if(data)
        memcpy(new->data, data, sizeof(struct course));
    new->next = NULL;
    return new;
}

struct course_list *init_course_list() {
    struct course_list *new = (struct course_list *)malloc(sizeof(struct course_list));
    new->head = NULL;
    new->size = 0;
    return new;
}

void insert_course_list(struct course_list *l, struct course *data) {
    struct course_list_node *insert = init_course_list_node(data);
    struct course_list_node *save = l->head;
    insert->next = save;
    l->head = insert;
    l->size += 1;
}

struct course_list *load_course_db() {
    struct course_list *courses = init_course_list();
    FILE *db = open_db(COURSE_DB, READ);
    if (db) {
        init_info();
        struct course *temp = init_course();
        while (fread(temp, sizeof(struct course), 1, db)) {
            insert_course_list(courses, temp);
            inc_course_count();
            memset(temp, 0, sizeof(struct course));
        }
        save_info();
        close_db(db);
        return courses;
    }
    return NULL;
}

void save_course_db(struct course_list *courses) {
    copy_db(COURSE_DB_BKP, COURSE_DB, OVERWRITE);
    FILE *db = open_db(COURSE_DB, OVERWRITE);
    if (db && courses) {
        struct course_list_node *trav = courses->head;
        while (trav) {
            if (fwrite(trav->data, sizeof(struct course), 1, db))
                trav = trav->next;
            else
                break;
        }
        close_db(db);
    }
}


