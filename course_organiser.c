#include <stdio.h>
#include <stdlib.h>

#include "app/app.h"
#include "course/course.h"
#include "course_list/course_list.h"
#include "database/file.h"
#include "util/util.h"

void main() {
    struct course_list *courses = load_course_db();
    if (!courses) {
        fprintf(stderr, "\nError: Unable to open database file. Exiting.");
        exit(1);
    }

    int choice;
    struct course_list_node *trav = init_course_list_node(NULL);

    while (1) {
        // system("clear");
        display_header();
        display_menu();
        scanf("%d", &choice);
        flush_stdin_buffer();
        switch (choice) {
            // system("clear");
            case 1:
                trav = courses->head;
                while (trav) {
                    print_course(trav->data);
                    trav = trav->next;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                save_course_db(courses);
                printf("\nExiting. Press any key to continue.\n");
                getchar();
                exit(0);
            default:
                printf("\nInvalid option. Press any key to continue.\n");
                getchar();
                break;
        }
    }
}