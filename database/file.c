#include "file.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../course/course.h"
#include "../course_list/course_list.h"

char* get_db_path(enum db_name db) {
    char* file_path = malloc(128);
    switch (db) {
        case COURSE_DB:
            strncpy(file_path, "database/course.db", 128);
            break;
        case COURSE_DB_BKP:
            strncpy(file_path, "database/course.db.bkp", 128);
            break;
        default:
            strncpy(file_path, "", 128);
    }
    return file_path;
}

FILE* open_db(enum db_name db_n, enum mode m) {
    FILE* db;
    char* file_path = get_db_path(db_n);
    switch (m) {
        case READ:
            db = fopen(file_path, "rb");
            return db;
        case WRITE:
        case APPEND:
            db = fopen(file_path, "ab");
            return db;
        case OVERWRITE:
            db = fopen(file_path, "w");
            return db;
    }
    return NULL;
}

void close_db(FILE* db) {
    if (db)
        fclose(db);
}

void copy_db(enum db_name db_dest, enum db_name db_src, enum mode write_mode) {
    FILE* src = open_db(db_src, READ);
    FILE* dest = open_db(db_dest, write_mode);
    if (src && dest) {
        int ch;
        while ((ch = fgetc(src)) != EOF) {
            fputc(ch, dest);
        }
        close_db(dest);
        close_db(src);
    }
}

int insert_course_db(struct course* record) {
    FILE* db = open_db(COURSE_DB, APPEND);
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

struct course_list* load_course_db() {
    struct course_list* courses = init_course_list();
    FILE* db = open_db(COURSE_DB, READ);
    if (db) {
        struct course* temp = init_course();
        while (fread(temp, sizeof(struct course), 1, db)) {
            insert_course_list(courses, temp);
            memset(temp, 0, sizeof(struct course));
        }
        close_db(db);
        return courses;
    }
    return NULL;
}

void save_course_db(struct course_list* courses) {
    copy_db(COURSE_DB_BKP, COURSE_DB, OVERWRITE);
    FILE* db = open_db(COURSE_DB, OVERWRITE);
    if (db && courses) {
        struct course_list_node* trav = courses->head;
        while (trav) {
            if (fwrite(trav->data, sizeof(struct course), 1, db))
                trav = trav->next;
            else
                break;
        }
        close_db(db);
    }
}
