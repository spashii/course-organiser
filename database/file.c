#include "file.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../course/course.h"
#include "../course_list/course_list.h"

FILE* open_course_db(int mode) {
    FILE* db;
    switch (mode) {
        case READ:
            db = fopen("database/course.db", "rb");
            return db;
        case WRITE:
            db = fopen("database/course.db", "ab");
            return db;
    }
    return NULL;
}

void close_db(FILE* db) {
    if (db)
        fclose(db);
}

int insert_course_db(struct course* record) {
    FILE* db = open_course_db(WRITE);
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
    FILE* db = open_course_db(READ);
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
