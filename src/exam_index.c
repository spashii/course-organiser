#include "exam_index.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"
#include "exam_list.h"
#include "util.h"

struct exam_list *exam_list;
struct exam_index *exam_index;
int sorted_by_exam_index;

void init_exam_index() {
    if (exam_list) {
        exam_index = malloc(sizeof(struct exam_index));
        exam_index->e = malloc(sizeof(struct exam *) * (exam_list->size));
        exam_index->size = exam_list->size;
    }
}

void load_exam_index() {
    int i = 0;
    printf("Indexing exams....\n");
    struct exam_list_node *trav = exam_list->head;
    while (trav && i < exam_index->size) {
        exam_index->e[i++] = trav->data;
        trav = trav->next;
    }
}

void sort_exam_index(enum exam_field_name sort_by) {
    if (exam_index) {
        int (*comparator)(const void *, const void *) =
            get_comparator_exam(sort_by);
        if (comparator) {
            qsort(exam_index->e, exam_index->size, sizeof(struct exam *),
                  comparator);
            sorted_by_exam_index = sort_by;
        }
    }
}

void free_exam_index() {
    free(exam_index->e);
    free(exam_index);
}

int search_exam_index(struct exam *key, enum exam_field_name sorted_by, int low,
                      int high) {
    if (sorted_by_exam_index != sorted_by) {
        sort_exam_index(sorted_by);
    }
    int (*comparator)(const void *, const void *) =
        get_comparator_exam(sorted_by);
    if (low > high || exam_index->size == 0) {
        return -1;
    } else {
        int mid = low + (high - low) / 2;
        // int mid = ((unsigned int)low + (unsigned int)high) >> 1;
        if (comparator(&(key), &(exam_index->e[mid])) == 0) {
            return mid;
        } else if (comparator(&(key), &(exam_index->e[mid])) < 0) {
            return search_exam_index(key, sorted_by, low, mid - 1);
        } else {
            return search_exam_index(key, sorted_by, mid + 1, high);
        }
    }
}

void make_exam_index(enum exam_field_name sort_by) {
    if (exam_index) {
        free(exam_index);
    }
    init_exam_index();
    load_exam_index();
    sort_exam_index(sort_by);
    printf("Indexed %d exams....\n", exam_index->size);
}

struct exam *get_by_id_exam_index(long id_key) {
    struct exam *search = init_exam(NULL);
    search->id = id_key;
    int index = search_exam_index(search, EXAM_ID, 0, exam_index->size);
    return index == -1 ? NULL : exam_index->e[index];
}

int print_exams_for_course(struct course *c) {
    if (sorted_by_exam_index != EXAM_DATETIME) {
        sort_exam_index(EXAM_DATETIME);
    }
    int i, count = 0;
    struct exam *e;
    printf("---------------------------------------------------------\n");
    for (i = 0; i < exam_index->size; i++) {
        e = exam_index->e[i];
        if (e->course_id == c->id) {
            print_short_exam(e);
            count++;
        }
    }
    if (count == 0)
        printf("| NO EXAMS FOR THIS COURSE                              |\n");
    printf("---------------------------------------------------------\n");
    return count;
}

void display_upcoming_exams(int count) {
    if (sorted_by_exam_index != EXAM_DATETIME) {
        sort_exam_index(EXAM_DATETIME);
    }
    int i;
    struct exam *e;
    printf("\nUPCOMING EXAMS\n");
    if (exam_index->size == 0) {
        printf("---------------------\n");
        printf("| NO UPCOMING EXAMS |\n");
        printf("---------------------\n");
        return;
    }
    time_t now = get_time();
    printf("----------------------------------------------------------\n");
    printf("| %-16s | %-16s | %-16s |\n", "COURSE CODE", "EXAM", "DATE");
    printf("----------------------------------------------------------\n");
    for (i = 0; count>0 && i < exam_index->size; i++) {
        e = exam_index->e[i];
        if (e->datetime > now) {
            printf("| %-16s | %-16s | %-16s |\n", get_course_code_exam(e),
                   e->name, get_datetime_format(e->datetime, "%d/%m"));
            count--;
        }
    }
    printf("----------------------------------------------------------\n");
    return;
}

int count_course_exam_index(struct course *c) {
    int count = 0;
    if (c) {
        int i;
        struct exam *e;
        for (i = 0; i < exam_index->size; i++) {
            e = exam_index->e[i];
            if ((is_active_exam(e)) && (e->course_id == c->id)) {
                count++;
            }
        }
    }
    return count;
}