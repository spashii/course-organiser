#ifndef _EXAM_INDEX_H_
#define _EXAM_INDEX_H_

#include "exam.h"
#include "exam_list.h"

struct exam_index {
    // an array of struct exam pointers which 
    // we will use to store struct exam ptrs
    struct exam **c;
    unsigned int size;
};

extern struct exam_index *exam_index;
extern int sorted_by_exam_index;

void init_exam_index();
void load_exam_index();
void sort_exam_index(enum exam_field_name sort_by);
void free_exam_index();
int search_exam_index(struct exam *key, enum exam_field_name search_field, int low, int high);

void make_exam_index(enum exam_field_name sort_by);

struct exam* get_by_id_exam_index(long id_key);

#endif