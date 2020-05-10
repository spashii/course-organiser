#include "exam_list.h"

//#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "exam.h"
#include "file.h"
#include "info.h"
#include "util.h"

struct exam_list *exam_list;

struct exam_list_node *init_exam_list_node(struct exam *data) {
    struct exam_list_node *new = malloc(sizeof(struct exam_list_node));
    new->data = init_exam(NULL);
    if (data)
        memcpy(new->data, data, sizeof(struct exam));
    new->next = NULL;
    return new;
}

void free_exam_list_node(struct exam_list_node *node) {
    if (node) {
        free(node->data);
        free(node);
    }
}

void init_exam_list() {
    exam_list = malloc(sizeof(struct exam_list));
    exam_list->head = NULL;
    exam_list->size = 0;
}

void load_exam_list() {
    init_exam_list();
    FILE *db = open_db(EXAM_DB, READ);
    if (db && exam_list) {
        load_info();
        reset_exam_count();
        struct exam *temp = init_exam(NULL);
        while (fread(temp, sizeof(struct exam), 1, db)) {
            insert_exam_list(temp);
            inc_exam_count();
            memset(temp, 0, sizeof(struct exam));
        }
        save_info();
        close_db(db);
    }
    printf("Loaded %d exams....\n", exam_list->size);
}

int is_unique_exam_list(struct exam *e) {
    struct exam_list_node *trav = exam_list->head;
    while (trav) {
        if (trav->data->datetime == e->datetime) {
            printf("Duplicate record (EXAM_DATETIME=%ld) found....\n",
                   e->datetime);
            return 0;
        }
        trav = trav->next;
    }
    return 1;
}

void insert_exam_list(struct exam *data) {
    xstrupr(data->name);
    xstrupr(data->details);
    xstrupr(data->location);
    if (is_unique_exam_list(data)) {
        struct exam_list_node *insert = init_exam_list_node(data);
        struct exam_list_node *save = exam_list->head;
        insert->next = save;
        exam_list->head = insert;
        exam_list->size += 1;
    }
}

void save_exam_list() {
    copy_db(EXAM_DB_BKP, EXAM_DB, OVERWRITE);
    FILE *db = open_db(EXAM_DB, OVERWRITE);
    if (db && exam_list) {
        load_info();
        reset_exam_count();
        struct exam_list_node *trav = exam_list->head;
        while (trav) {
            if (fwrite(trav->data, sizeof(struct exam), 1, db)) {
                trav = trav->next;
                inc_exam_count();
            } else {
                break;
            }
        }
        save_info();
        close_db(db);
    }
}

void free_exam_list() {
    if (exam_list->head) {
        struct exam_list_node *trav = exam_list->head;
        struct exam_list_node *trav_next;
        while (trav->next) {
            trav_next = trav->next;
            free_exam_list_node(trav);
            trav = trav_next;
        }
        free(exam_list);
    }
}

void delete_in_exam_list(long id) {
    struct exam_list_node *temp = exam_list->head;
    if (temp->data->id == id) {
        exam_list->head = temp->next;
        free_exam_list_node(temp);
        exam_list->size -= 1;
    } else {
        struct exam_list_node *trav = temp;
        struct exam_list_node *prev;
        while (trav->data->id != id) {
            prev = trav;
            if (trav->next == NULL) {
                return;
            }
            trav = trav->next;
        }
        prev->next = trav->next;
        free_exam_list_node(trav);
        exam_list->size -= 1;
    }
}

void delete_exams_of_course_exam_list(long course_id) {
    struct exam_list_node *temp = exam_list->head;
    while(temp){
        if(temp->data->course_id == course_id) {
            delete_in_exam_list(temp->data->id);
        }
        temp = temp->next;
    }
}