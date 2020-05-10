#include "menu.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "course_index.h"
#include "course_operation.h"
#include "exam.h"
#include "exam_index.h"
#include "exam_operation.h"
#include "util.h"

struct course_index *course_index;
struct exam_index *exam_index;

void main_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - MAIN MENU");
        nl();
        print_datetime(get_time());
        nl();
        display_upcoming_exams(5);
        nl();
        printf("MENU\n");
        printf("1. Course Menu\n");
        printf("2. Exam Menu\n");
        printf("3. Info\n");
        printf("4. Exit\n");
        nl();
        printf("Your Choice : ");
        scanf("%d", &control);
        // control = 3;
        flush_stdin_buffer();
        switch (control) {
            case 1:
                course_menu();
                break;
            case 2:
                exam_menu();
                break;
            case 3:
                display_exam_course_menu(course_index->c[10]);
                break;
            case 4:
                return;
            default:
                printf("Invalid option. Press enter to continue.");
                getchar();
        }
    }
}

void course_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - COURSE MENU");
        nl();
        print_datetime(get_time());
        nl();
        display_upcoming_exams(5);
        nl();
        printf("MENU\n");
        printf("1. Search Course\n");
        printf("2. Manage Course(Display, View Exams, Edit, Delete)\n");
        printf("3. Add Course\n");
        printf("4. Return\n");
        nl();
        printf("Your Choice : ");
        scanf("%d", &control);
        flush_stdin_buffer();
        switch (control) {
            case 1:
                search_course_menu();
                break;
            case 2:
                display_all_courses_menu();
                break;

            case 3:
                insert_course_operation();
                display_all_courses_menu();
                break;
            case 4:
                return;
            default:
                printf("Invalid option. Press enter to continue.");
                getchar();
        }
    }
}

void display_all_courses_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - COURSE");
        nl();
        print_datetime(get_time());
        nl();
        if (!(course_index->size)) {
            printf("\n-------------------------\n");
            printf("| NO COURSES TO DISPLAY |\n");
            printf("------------------------\n");
            printf("\nPress enter to continue.");
            getchar();
            return;
        } else {
            display_code_name_course_operation();
            printf("\nSelect a course(1 - %d) or press '0' to continue : ",
                   course_index->size);
            scanf("%d", &control);
            flush_stdin_buffer();
            if (control == 0) {
                break;
            } else if (control > 0 && control <= course_index->size) {
                display_course_menu(control - 1);
            } else {
                continue;
            }
        }
    }
}

void display_course_menu(int index) {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - %s", course_index->c[index]->code);
        nl();
        print_datetime(get_time());
        nl();
        printf("\nCOURSE\n");
        print_course(course_index->c[index]);
        printf("\n\nEXAMS\n");
        print_exams_for_course(course_index->c[index]);
        nl();
        printf("MENU\n");
        printf("1. Add Exam\n");
        printf("2. Manage Exams\n");
        printf("3. Edit Course\n");
        printf("4. Delete Course\n");
        printf("5. Return\n");
        nl();
        printf("Your Choice : ");
        scanf("%d", &control);
        flush_stdin_buffer();
        switch (control) {
            case 1:
                insert_exam_operation(course_index->c[index]);
                break;
            case 2:
                display_exam_course_menu(course_index->c[index]);
                break;
            case 3:
                edit_course_operation(course_index->c[index]);
                break;
            case 4:
                printf("Are you sure you want to delete this course(y/n)? ");
                control = getchar();
                if (control == (int)'y' || control == (int)'Y') {
                    delete_course_operation(course_index->c[index]);
                }
                printf("\nPress enter to continue...");
                getchar();
                return;
            case 5:
                return;
            default:
                printf("Invalid option. Press enter to continue.");
                getchar();
        }
    }
}

void display_exam_course_menu(struct course *c) {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - %s EXAMS", c->code);
        nl();
        print_datetime(get_time());
        nl();
        int count = count_course_exam_index(c);
        printf("\nLIST OF EXAMS FOR %s\n\n", c->code);
        if (count == 0) {
            printf("----------------------\n");
            printf("| NO EXAMS TO MANAGE |\n");
            printf("----------------------\n");
            printf("\nPress enter to continue.");
            getchar();
            return;
        } else {
            int i;
            struct exam *e;
            printf(
                "--------------------------------------------------------------"
                "------\n");
            printf("| %-2s | %-16s | %-10s | %-8s | %-16s |\n", "NO", "EXAM",
                   "DATE", "TIME", "LOCATION");
            printf(
                "--------------------------------------------------------------"
                "------\n");
            int k = 0;
            for (i = 0; i < exam_index->size; i++) {
                e = exam_index->e[i];
                if (e->course_id == c->id) {
                    printf("| %-2d | %-16s | %-10s | %-8s | %-16s |\n", ++k,
                           e->name,
                           get_datetime_format(e->datetime, "%d/%m/%Y"),
                           get_datetime_format(e->datetime, "%I:%M %p"),
                           e->location);
                }
            }
            printf(
                "--------------------------------------------------------------"
                "------\n");
            printf("\nSelect an exam(1-%d) or press '0' to continue : ", k);
            scanf("%d", &control);
            flush_stdin_buffer();
            if (control == 0) {
                return;
            } else if (control > 0 && control <= k) {
                for (i = 0; i < exam_index->size; i++) {
                    e = exam_index->e[i];
                    if (e->course_id == c->id) {
                        control--;
                        if (control == 0) {
                            break;
                        }
                    }
                }
                display_exam_menu(i);
            } else {
                printf("\nInvaild option. Press enter to continue.\n");
                getchar();
                break;
            }
        }
    }
}

void search_course_menu() {
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - SEARCH COURSE MENU");
        nl();
        print_datetime(get_time());
        nl();
        nl();
        char *code_key;
        printf("Enter Course Code? ");
        code_key = s_readline(16);
        if (strlen(code_key) == 0) {
            return;
        }
        int index = search_course_operation(code_key);
        if (index == -1) {
            printf("\nCourse \"%s\" not found. Press enter to continue.",
                   code_key);
            getchar();
            free(code_key);
            return;
        }
        printf("\nCourse \"%s\" found. Press enter to continue.",
               xstrupr(code_key));
        getchar();
        display_course_menu(index);
        free(code_key);
        return;
    }
}

void exam_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - EXAM MENU");
        nl();
        print_datetime(get_time());
        nl();
        display_upcoming_exams(5);
        nl();
        printf("MENU\n");
        printf("1. Display Active Exams\n");
        // printf("2. Display Exams for a Specific Course");
        printf("2. Display All Exams\n");
        printf("3. Return\n");
        nl();
        printf("Your Choice : ");
        scanf("%d", &control);
        flush_stdin_buffer();
        switch (control) {
            case 1:
                display_active_exams_menu();
                break;
            case 2:
                display_all_exams_menu();
                break;
            case 3:
                return;
            default:
                printf("Invalid option. Press enter to continue.");
                getchar();
        }
    }
}

void display_active_exams_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - EXAM MENU");
        nl();
        print_datetime(get_time());
        nl();
        if (!(exam_index->size)) {
            printf("\n-----------------------\n");
            printf("| NO EXAMS TO DISPLAY |\n");
            printf("-----------------------\n");
            printf("\nPress enter to continue.");
            getchar();
            return;
        } else {
            int i;
            struct exam *e;
            printf("\nLIST OF ACTIVE EXAMS\n\n");
            printf(
                "--------------------------------------------------------------"
                "---------------------"
                "----\n");
            printf("| %-2s | %-16s | %-16s | %-10s | %-8s | %-16s |\n", "NO",
                   "COURSE NAME", "EXAM", "DATE", "TIME", "LOCATION");
            printf(
                "--------------------------------------------------------------"
                "-------------------"
                "------\n");
            int k = 0;
            for (i = 0; i < exam_index->size; i++) {
                e = exam_index->e[i];
                if (is_active_exam(e)) {
                    printf("| %-2d | %-16s | %-16s | %-10s | %-8s | %-16s |\n",
                           ++k, get_course_code_exam(e), e->name,
                           get_datetime_format(e->datetime, "%d/%m/%Y"),
                           get_datetime_format(e->datetime, "%I:%M%p"),
                           e->location);
                }
            }
            printf(
                "--------------------------------------------------------------"
                "--------------------"
                "-----\n");
            printf("\nSelect an exam(1-%d) or press '0' to continue : ", k);
            scanf("%d", &control);
            flush_stdin_buffer();
            if (control == 0) {
                break;
            } else if (control > 0 && control <= k) {
                for (i = 0; i < exam_index->size; i++) {
                    e = exam_index->e[i];
                    if (is_active_exam(e)) {
                        control--;
                        if (control == 0) {
                            break;
                        }
                    }
                }
                display_exam_menu(i);
            } else {
                printf("\nInvaild option. Press enter to continue.\n");
                getchar();
                break;
            }
        }
    }
}

void display_all_exams_menu() {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - EXAM MENU");
        nl();
        print_datetime(get_time());
        nl();
        if (!(exam_index->size)) {
            printf("\n-----------------------\n");
            printf("| NO EXAMS TO DISPLAY |\n");
            printf("-----------------------\n");
            printf("\nPress enter to continue.");
            getchar();
            return;
        } else {
            printf("\nLIST OF ALL EXAMS\n\n");
            int i;
            struct exam *e;
            printf(
                "--------------------------------------------------"
                "----"
                "--------"
                "-"
                "---------------------------------\n");
            printf(
                "| %-2s | %-16s | %-16s | %-10s | %-8s | %-16s | "
                "%-6s "
                "|\n",
                "NO", "COURSE NAME", "EXAM", "DATE", "TIME", "LOCATION",
                "STATUS");
            printf(
                "--------------------------------------------------"
                "----"
                "--------"
                "-"
                "---------------------------------\n");
            for (i = 0; i < exam_index->size; i++) {
                e = exam_index->e[i];
                if (e->course_id)
                    printf(
                        "| %-2d | %-16s | %-16s | %-10s | %-8s | "
                        "%-16s "
                        "| %-6s "
                        "|\n",
                        i + 1, get_course_code_exam(e), e->name,
                        get_datetime_format(e->datetime, "%d/%m/%Y"),
                        get_datetime_format(e->datetime, "%I:%M%p"),
                        e->location, is_active_exam(e) ? "ACTIVE" : "");
            }
            printf(
                "--------------------------------------------------"
                "----"
                "--------"
                "-"
                "---------------------------------\n");
            printf(
                "\nSelect an exam(1-%d) or press '0' to continue "
                ": ",
                exam_index->size);
            scanf("%d", &control);
            flush_stdin_buffer();
            if (control == 0) {
                break;
            } else if (control > 0 && control <= exam_index->size) {
                display_exam_menu(control - 1);
            } else {
                continue;
            }
        }
    }
}

void display_exam_menu(int index) {
    int control;
    while (1) {
        clear_screen();
        nl();
        printf("COURSE ORGANISER - EXAM");
        nl();
        print_datetime(get_time());
        nl();
        printf("\nEXAM\n");
        print_exam(exam_index->e[index]);
        nl();
        printf("MENU\n");
        printf("1. Edit Exam\n");
        printf("2. Delete Exam\n");
        printf("3. Return\n");
        nl();
        printf("Your Choice : ");
        scanf("%d", &control);
        flush_stdin_buffer();
        switch (control) {
            case 1:
                edit_exam_operation(exam_index->e[index]);
                return;
            case 2:
                printf("Are you sure you want to delete this exam(y/n)? ");
                control = getchar();
                if (control == (int)'y' || control == (int)'Y') {
                    delete_exam_operation(exam_index->e[index]);
                }
                printf("\nPress enter to continue...");
                getchar();
                return;
            case 3:
                return;
            default:
                printf("Invalid option. Press enter to continue.");
                getchar();
        }
    }
}

void info_menu() {}
