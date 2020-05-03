#include <stdio.h>
#include <string.h>

#include "course.h"
#include "course_index.h"
#include "course_list.h"
#include "file.h"
#include "info.h"
#include "util.h"

struct course_index *course_index;
struct course_list *course_list;

int main() {
    // load_course_list();
    // sort_course_index(COURSE_CODE);
    // make_course_index();
    // free_course_index();
    // free_course_list();
    // load_course_list();
    // make_course_index();
    // sort_course_index(COURSE_CREDIT);

    // free_course_index();
    // free_course_list();

    load_course_list();
    make_course_index(COURSE_CODE);

    int i;
    for (i = 0; i < course_index->size; i++) {
        printf("%d", i);
        print_course(course_index->c[i]);
    }

    // insert_course_db(set_course(init_course(), "nba", "nambia", 50));
    printf("\n=----=-=\n");

    int s = search_course_index(set_course(init_course(), "salad", "", 0.0), COURSE_CODE, 0, course_index->size);
    printf("%d", s);

    // printf("\n%d", get_by_code_course_index("abc"));

    // make_course_index(COURSE_CREDIT);

    // for (i = 0; i < course_index->size; i++) {
    //     print_course(course_index->c[i]);
    // }
    free_course_index();
    free_course_list();

    // insert_course_db(set_course(init_course(), "d", "eggg", 1.5));
    // insert_course_db(set_course(init_course(), "s", "salad ", 1.0));
    //     insert_course_db(set_course(init_course(), "wwwwwwcod4", "hello uiop", 1.0));
    //     insert_course_db(set_course(init_course(), "dfgh dcod5", "312zzzzzzsdfa", 1.0));

    // // struct course *temp = init_course();
    // // // db = open_course_db(READ);
    // // // if (db) {
    // // //     while (fread(temp, sizeof(struct course), 1, db)) {
    // // //         if (temp)
    // // //             print_course(temp);
    // // //     }
    // // // }

    // // struct course_list *courses = load_course_db();
    // // struct course_list_node *test;

    // // test = courses->head;
    // // while (test) {
    // //     printf("%ld;", (test->data)->id);
    // //     printf("%s\n", (test->data)->code);
    // //     test = test->next;
    // // }

    // // insert_course_list(courses, input_course(init_course()));

    // // save_course_db(courses);

    // // courses = load_course_db();

    // // test = courses->head;
    // // while (test) {
    // //     printf("%ld;", (test->data)->id);
    // //     printf("%s\n", (test->data)->code);
    // //     test = test->next;
    // // }

    // // //print_course(input_course(init_course()));
    // // // struct course *new = init_course();
    // // // new = input_course(new);
    // // // print_course(new);
    // // struct course *c1 = init_course();
    // // c1 = input_course(c1);
    // // print_course(c1);

    // // insert_course_db(c1);

    // // FILE *db = open_db(COURSE_DB, READ);

    // // fread(c, sizeof(struct course), 1, db);

    // // print_course(c);

    // // struct course_list *courses = load_course_db();

    // // struct course_list_node *trav = courses->head;
    // // while(trav){
    // //     print_course(trav->data);
    // //     trav = trav->next;
    // // }
    // // load_info();
    // // printf("%u, %u\n", 0, APP_INFO.course_count);

    // // load_course_list();

    // // make_course_index();

    // // sort_course_index(COURSE_NAME);

    // // struct course_list_node *trav = courses->head;
    // // while(trav){
    // //     print_course(trav->data);
    // //     trav = trav->next;
    // // }

    // // printf("%ld, %u", sizeof(course_index)/sizeof(**course_index), courses->size);

    // // save_course_db(courses);

    // // int i = 0;
    // // for (i = 0; i < course_index->size; i++) {
    // //     print_course(course_index->c[i]);
    // // }

    //
    // // save_course_list();
    // // free_course_list();
    // load_course_list();

    // make_course_index();

    // sort_course_index(COURSE_CODE);
    // sort_course_index(COURSE_CREDIT);

    // free_course_list();

    // // print_course(course_index[3]);
    // // print_course(course_index[2]);
    // // printf("%d", strncmp(course_index[3]->code, course_index[2]->code, 16));
    // // printf("%d", compare_course_code(course_index[0], course_index[1]));

    // // load_course_list();

    // // make_course_index();

    // // sort_course_index(COURSE_CREDIT);

    // // int i= 0;
    // // for (i = 0; i < course_list->size; i++) {
    // //     print_course(course_index[i]);
    // // }

    // //  free_course_list();
}