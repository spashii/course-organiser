#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

#include "course.h"
#include "course_index.h"
#include "course_list.h"
#include "course_operation.h"
#include "exam.h"
#include "file.h"
#include "info.h"
#include "util.h"

struct course_index *course_index;
struct course_list *course_list;

int main() {
    init_course_operation();
    // display_code_name_course_operation();
    char code[16] = "CODeNAMe";
    char name[128] = "nawdef";
    struct course *c = set_course(init_course(), code, name, 8);
    c->id = 1000;
    print_course(c);
    struct exam *e = init_exam(c);
    insert_course_list(c);
    make_course_index(COURSE_CODE);
    display_code_name_course_operation();
    print_exam(e);

    // init_course_operation();
    // // print_course(course_index->c[1]);
    // sort_course_index(COURSE_ID);
    // struct course *c = get_by_id_course_index(1588880087);
    // if (c)print_course(c);
    // int i;
    // for(i =0 ; i<10; i++){
    //     print_course(course_index->c[i]);
    // }
}