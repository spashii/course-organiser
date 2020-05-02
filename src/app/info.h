#ifndef _INFO_H
#define _INFO_H

struct info{
    unsigned int course_count;
};

extern struct info APP_INFO;

void init_info();
void load_info();
void inc_course_count();
void dec_course_count();
void save_info();

#endif