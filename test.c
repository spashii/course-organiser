#include <stdio.h>

#include "course/course.h"
// #include "exam/exam.h"
#include "database/file.h"
// #include "info/info.h"
#include "util/util.h"
#include "list/list.h"

int main() {
    FILE *db;
    struct course *new = input_course(init_course());
    // struct course new = {12345, "111111111111111", "77777777777777777thjrjurtj7777777777777777777777777777thjrjurtj5", 3.3};
    db = open_course_db(WRITE);
    insert_course_record(db, new);
    close_db(db);

    // struct course *temp = init_course();
    // db = open_course_db(READ);
    // if (db) {
    //     while (fread(temp, sizeof(struct course), 1, db)) {
    //         if (temp)
    //             print_course(temp);
    //     }
    // }

    struct list *courses = load_course_db();

    struct list_node *test = courses->head;

    while(test){
        printf("id: %d\n", ((struct course *)(test->data))->id);
        test = test->next;
    }

    close_db(db);

    
    //print_course(input_course(init_course()));
    // struct course *new = init_course();
    // new = input_course(new);
    // print_course(new);
}