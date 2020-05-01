#ifndef _FILE_H_
#define _FILE_H_

#include "../course/course.h"
#include "../exam/exam.h"
//#include "../info/info.h"
#include "../list/list.h"

#include <stdio.h>

enum modes {
    READ,
    WRITE,
};

FILE* open_course_db(int mode);
void close_db(FILE* db);

int insert_course_db(struct course *record);
struct list* load_course_db();



#endif
