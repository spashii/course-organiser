#include "info.h"

#include <malloc.h>
#include <stdio.h>

#include "file.h"

struct info APP_INFO;

void init_info() {
    APP_INFO.course_count = 0;
    APP_INFO.exam_count = 0;
}

void load_info() {
    FILE *i = open_db(INFO_DB, READ);
    if (i) {
        if (fread(&APP_INFO, sizeof(struct info), 1, i)) {
            close_db(i);
            return;
        }
    }
}

void inc_course_count() { APP_INFO.course_count += 1; }

void dec_course_count() { APP_INFO.course_count -= 1; }

void inc_exam_count() {APP_INFO.exam_count += 1;}

void dec_exam_count() {APP_INFO.exam_count += 1;}

void save_info() {
    FILE *i = open_db(INFO_DB, OVERWRITE);
    if (i) {
        if (fwrite(&APP_INFO, sizeof(struct info), 1, i)) {
            close_db(i);
            return;
        }
    }
}
