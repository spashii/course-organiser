#ifndef _MENU_H_
#define _MENU_H_

#include "course.h"

void main_menu();
void course_menu();
void display_all_courses_menu();
void display_course_menu(int index);
void display_exam_course_menu(struct course *c);
void search_course_menu();
void exam_menu();
void display_all_exams_menu();
void display_active_exams_menu();
void display_course_specific_exam_menu();
void display_exam_menu(int index);
void info_menu();

#endif