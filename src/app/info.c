#include "info.h"

#include <malloc.h>
#include <stdio.h>

struct info APP_INFO;

// void load_app_path(){
//     APP_PATH = getenv("COURSE_ORGANISER_PATH");
// }

// char *app_path(){
//     return APP_PATH;
// }

void init_info() {
    APP_INFO.course_count = 0;
    // APP_INFO.exam_count = 0;
}

void load_info() {
    FILE *i;
    if ((i = fopen("info.db", "r"))) {
        if (fread(&APP_INFO, sizeof(struct info), 1, i)) {
            fclose(i);
            return;
        }
    }
    init_info();
    save_info();
}

void inc_course_count() {
    APP_INFO.course_count += 1;
}

void dec_course_count() {
    APP_INFO.course_count -= 1;
}

void save_info() {
    FILE *i;
    if ((i = fopen("info.db", "w"))) {
        if (fwrite(&APP_INFO, sizeof(struct info), 1, i)) {
            fclose(i);
            return;
        }
    }
}
