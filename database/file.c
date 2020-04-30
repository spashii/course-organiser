#include "file.h"

#include <malloc.h>
#include <stdio.h>

#include "../course/course.h"

FILE* open_course_db(int mode) {
  FILE* db = (FILE*)malloc(sizeof(FILE));
  switch (mode) {
    case READ:
      db = fopen("database/course.db", "rb");
      break;
    case WRITE:
      db = fopen("database/course.db", "ab");
      break;
    default:
      db = NULL;
      break;
  }
  return db;
}

int insert_course_record(FILE* db, struct course* record) {
  if (db != NULL) {
    fwrite(record, sizeof(struct course), 1, db);
    return 0;
  }
  return -1;
}

struct list* load_course_db(){
  struct list *courses = init_list();
  FILE *db = open_course_db(READ);
  struct course *temp = init_course();
  while(db){
    if(fread(temp, sizeof(struct course), 1, db)){
      insert_list(courses, temp);
    }
  }
  return courses;
}

void close_db(FILE* db) {
  if (db)
    fclose(db);
}