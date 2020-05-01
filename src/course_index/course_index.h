#ifndef _COURSE_INDEX_H_
#define _COURSE_INDEX_H_

#include "../course/course.h"
#include "../course_list/course_list.h"

struct course **course_index;

void init_course_index(struct course_list *courses);
void make_course_index(struct course_list *courses);

int qs_partition_course_index(struct course **arr, int low, int high);
int qs_partition_r_course_index(struct course **arr, int low, int high);
void qs_course_index(struct course **arr, int low, int high);
void qs_swap_course_index(struct course **a, struct course **b);

#endif