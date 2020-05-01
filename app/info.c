#include "info.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct info* init_info() {
    struct info* new = (struct info*)malloc(sizeof(struct info));
    new->course_count = 0;
    new->exam_count = 0;
}

void load_app_path(){
    APP_PATH = getenv("COURSE_ORGANISER_PATH");
}

char *app_path(){
    return APP_PATH;
}