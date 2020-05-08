#include "exam_operation.h"

#include "exam_list.h"

void init_exam_operation(){
    load_exam_list();
}

void save_exam_operation(){
    save_exam_list();
    free_exam_list();
}