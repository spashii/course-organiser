#ifndef _INFO_H
#define _INFO_H

// extern char* APP_PATH;

// void load_app_path();
// char* app_path();

struct info{
    unsigned int course_count;
    // unsigned int exam_count;
};

struct info APP_INFO;

void init_info();
void load_info();
void inc_course_count();
void dec_course_count();
void save_info();

#endif