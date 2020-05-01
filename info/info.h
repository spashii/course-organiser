#ifndef _INFO_H
#define _INFO_H

char* APP_PATH;

struct info{
    unsigned int course_count;
    unsigned int exam_count;
};

struct info* init_info();

void load_app_path();
char* app_path();

#endif