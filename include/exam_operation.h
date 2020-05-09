#ifndef _EXAM_OPERATION_H_
#define _EXAM_OPERATION_H_

#include "course.h"
#include "exam.h"

void init_exam_operation();
void display_code_name_date_exam_operation();
void delete_exam_operation(struct exam *e);
void edit_exam_operation(struct exam *e);
void insert_exam_operation(struct course *c);
void save_exam_operation();

#endif