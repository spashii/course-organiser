#include <stdio.h>

#include "course/course.h"
#include "course_list/course_list.h"
// #include "exam/exam.h"
#include "database/file.h"
// #include "info/info.h"
#include "util/util.h"
// #include "list/list.h"

int main() {
    
    // insert_course_db(set_course(init_course(), "cod1", "", 1.0));
    // insert_course_db(set_course(init_course(), "cod2", "", 1.0));
    // insert_course_db(set_course(init_course(), "cod3", "", 1.0));
    // insert_course_db(set_course(init_course(), "cod4", "", 1.0));
    // insert_course_db(set_course(init_course(), "cod5", "", 1.0));

    // struct course *temp = init_course();
    // db = open_course_db(READ);
    // if (db) {
    //     while (fread(temp, sizeof(struct course), 1, db)) {
    //         if (temp)
    //             print_course(temp);
    //     }
    // }


    struct course_list *courses = load_course_db();
    struct course_list_node *test = courses->head;
    while(test){
        printf("%ld;", (test->data)->id);
        printf("%s\n", (test->data)->code);
        test = test->next;
    }

    //print_course(input_course(init_course()));
    // struct course *new = init_course();
    // new = input_course(new);
    // print_course(new);
}