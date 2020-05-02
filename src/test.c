#include <stdio.h>
#include <string.h>

#include "course/course.h"
#include "course_index/course_index.h"
#include "course_list/course_list.h"
// #include "exam/exam.h"
#include "app/info.h"
#include "database/file.h"
#include "util/util.h"
// #include "list/list.h"

long cmp(const void *a, const void *b){
    return (strcmp((char *)a, (char *)b));
}

int main() {
    //  insert_course_db(set_course(init_course(), "zzzz", "names23232", 1.6));
    // insert_course_db(set_course(init_course(), "mmmmcod2", "eary", 1.0));
    // insert_course_db(set_course(init_course(), "rrrrcod3", "salad ", 1.0));
    // insert_course_db(set_course(init_course(), "wwwwwwcod4", "hello uiop", 1.0));
    // insert_course_db(set_course(init_course(), "dfgh dcod5", "312zzzzzzsdfa", 1.0));

    // // struct course *temp = init_course();
    // // db = open_course_db(READ);
    // // if (db) {
    // //     while (fread(temp, sizeof(struct course), 1, db)) {
    // //         if (temp)
    // //             print_course(temp);
    // //     }
    // // }

    // struct course_list *courses = load_course_db();
    // struct course_list_node *test;

    // test = courses->head;
    // while (test) {
    //     printf("%ld;", (test->data)->id);
    //     printf("%s\n", (test->data)->code);
    //     test = test->next;
    // }

    // insert_course_list(courses, input_course(init_course()));

    // save_course_db(courses);

    // courses = load_course_db();

    // test = courses->head;
    // while (test) {
    //     printf("%ld;", (test->data)->id);
    //     printf("%s\n", (test->data)->code);
    //     test = test->next;
    // }

    // //print_course(input_course(init_course()));
    // // struct course *new = init_course();
    // // new = input_course(new);
    // // print_course(new);
    // struct course *c1 = init_course();
    // c1 = input_course(c1);
    // print_course(c1);

    // insert_course_db(c1);

    // FILE *db = open_db(COURSE_DB, READ);

    // fread(c, sizeof(struct course), 1, db);

    // print_course(c);

    // struct course_list *courses = load_course_db();

    // struct course_list_node *trav = courses->head;
    // while(trav){
    //     print_course(trav->data);
    //     trav = trav->next;
    // }
    // load_info();
    // printf("%u, %u\n", 0, APP_INFO.course_count);

    struct course_list *courses = load_course_db();

    // make_course_index(courses);

    struct course_list_node *trav = courses->head;
    // while(trav){
    //     print_course(trav->data);
    //     trav = trav->next;
    // }

    // printf("%ld, %u", sizeof(course_index)/sizeof(**course_index), courses->size);

    // save_course_db(courses);

    // int i = 0;
    // for (i = 0; i < courses->size; i++) {
    //     print_course(course_index[i]);
    // }

    // print_course(course_index[3]);
    // print_course(course_index[2]);
    // printf("%d", strncmp(course_index[3]->code, course_index[2]->code, 16));
    // printf("%d", compare_course_code(course_index[0], course_index[1]));

    avltree_t *new = avltree_new(cmp);

    avltree_insert(new, trav);

}

