#include "menu.h"
#include "course_operation.h"
#include "exam_operation.h"
#include "util.h"

#include<stdio.h>

int main() {
    clear_screen();
    printf("Initializing app....\n");
    printf("Loading courses....\n");
    init_course_operation();
    printf("Loading exams....\n");
    init_exam_operation();
    printf("\nPress enter to continue...");
    getchar();
    main_menu();
    save_course_operation();
}
