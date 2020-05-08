#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "course.h"
#include "course_index.h"
#include "course_list.h"
#include "course_operation.h"
#include "exam.h"
#include "exam_list.h"
#include "file.h"
#include "info.h"
#include "util.h"

struct course_index *course_index;
struct course_list *course_list;
struct exam_list *exam_list;

int main() {
    init_course_operation();
    display_code_name_course_operation();

    // struct exam *e1 = input_exam(init_exam_by_course_code("PHY101"));
    // struct exam *e2 = input_exam(init_exam_by_course_code("CSD101"));
    // struct exam *e3 = input_exam(init_exam_by_course_code("PHY101"));

    load_exam_list();
    // insert_exam_list(e1);
    // insert_exam_list(e2);
    // insert_exam_list(e3);

    struct exam_list_node *e = exam_list->head;

    while(e){
        print_exam(e->data);
        e = e->next;
    }

    delete_in_exam_list(1588970607);

    // save_exam_list();
    printf("---------");
    e = exam_list->head;
    while(e){
        print_exam(e->data);
        e = e->next;
    }
    

    free_exam_list();
}