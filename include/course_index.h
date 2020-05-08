#ifndef _COURSE_INDEX_H_
#define _COURSE_INDEX_H_

#include "course.h"
#include "course_list.h"

struct course_index {
     // an array of struct course pointers which 
    // we will use to store struct course ptrs
    struct course **c;
    unsigned int size;
};

extern struct course_index *course_index;
extern int sorted_by_course_index;

void init_course_index();
void load_course_index();
void sort_course_index(enum course_field_name sort_by);
void free_course_index();
int search_course_index(struct course *key, enum course_field_name search_field, int low, int high);

void make_course_index(enum course_field_name sort_by);

int get_index_by_code_course_index(char *code_key);
struct course* get_by_code_course_index(char *code_key);
struct course* get_by_id_course_index(long id_key);

#endif