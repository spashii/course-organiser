#include "course.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../util/util.h"

struct course* init_course(void) {
  struct course* new = (struct course*)malloc(sizeof(struct course));
  new->id = get_time();
  strncpy(new->code, "", 16);
  strncpy(new->name, "", 128);
  new->credit = 0.0;
  return new;
}

void print_course(struct course* c) {
  printf("\nID      : %ld\n", c->id);
  printf("Code    : %s\n", c->code);
  printf("Name    : %s\n", c->name);
  printf("Credits : %.1f\n", c->credit);
}

void set_course(struct course* c, char code[], char name[], float credit) {
  strncpy(c->code, code, 16);
  strncpy(c->name, name, 128);
  c->credit = credit;
}

struct course* input_course(struct course* c) {
  printf("Course Code? ");
  char* code = s_readline(16);
  printf("Course Name? ");
  char* name = s_readline(128);
  printf("Course Credits? ");
  float credit;
  scanf("%f", &credit);
  flush_stdin_buffer();
  set_course(c, code, name, credit);
  return c;
}