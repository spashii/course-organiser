#ifndef _COURSE_OPERATION_C_
#define _COURSE_OPERATION_C_

#include "course.h"

void init_course_operation();
void display_code_name_course_operation();
void delete_course_operation(struct course *c);
void edit_course_operation(struct course *c);
void insert_course_operation();
void save_course_operation();
int search_course_operation(char *code_key);

#endif