#ifndef _INFO_H
#define _INFO_H

struct info {
    unsigned int course_count;
    unsigned int exam_count;
};

extern struct info APP_INFO;

void init_info();
void load_info();
void reset_course_count();
void inc_course_count();
void dec_course_count();
void reset_exam_count();
void inc_exam_count();
void dec_exam_count();
void save_info();

#endif