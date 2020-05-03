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
    load_course_list();
    make_course_index(COURSE_CODE);

    int i;
    for (i = 0; i < course_index->size; i++) {
        printf("%d", i);
        print_course(course_index->c[i]);
    }
    printf("\n=----=-=\n");
    int s;
    s = get_by_code_course_index("nba");
    printf("\n%d\n", s);
    s = get_by_code_course_index("NBA");
    printf("\n%d\n", s);
    s = get_by_code_course_index("nba");
    printf("\n%d\n", s);
    s = get_by_code_course_index("smaeer");
    printf("\n%d\n", s);
    s = get_by_code_course_index("WWWWWWCOD4");
    printf("\n%d\n", s);

    free_course_index();
    free_course_list();

}