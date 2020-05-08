#include "course_index.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "course.h"
#include "course_list.h"
#include "util.h"

struct course_list *course_list;
struct course_index *course_index;
int sorted_by_course_index;

void init_course_index() {
    if (course_list) {
        course_index = malloc(sizeof(struct course_index));
        course_index->c = malloc(sizeof(struct course *) * (course_list->size));
        course_index->size = course_list->size;
    }
}

void load_course_index() {
    int i = 0;
    printf("Indexing courses....\n");
    struct course_list_node *trav = course_list->head;
    while (trav && i < course_index->size) {
        course_index->c[i++] = trav->data;
        trav = trav->next;
    }
}

void sort_course_index(enum course_field_name sort_by) {
    if (course_index) {
        int (*comparator)(const void *, const void *) =
            get_comparator_course(sort_by);
        if (comparator) {
            qsort(course_index->c, course_index->size, sizeof(struct course *),
                  comparator);
            sorted_by_course_index = sort_by;
        }
    }
}

void free_course_index() {
    free(course_index->c);
    free(course_index);
}

int search_course_index(struct course *key, enum course_field_name sorted_by,
                        int low, int high) {
    if (sorted_by_course_index != sorted_by) {
        sort_course_index(sorted_by);
    }
    int (*comparator)(const void *, const void *) =
        get_comparator_course(sorted_by);
    if (low > high || course_index->size == 0) {
        return -1;
    } else {
        int mid = low + (high - low) / 2;
        // int mid = ((unsigned int)low + (unsigned int)high) >> 1;
        if (comparator(&(key), &(course_index->c[mid])) == 0) {
            return mid;
        } else if (comparator(&(key), &(course_index->c[mid])) < 0) {
            return search_course_index(key, sorted_by, low, mid - 1);
        } else {
            return search_course_index(key, sorted_by, mid + 1, high);
        }
    }
}

void make_course_index(enum course_field_name sort_by) {
    if (course_index) {
        free(course_index);
    }
    init_course_index();
    load_course_index();
    sort_course_index(sort_by);
    printf("Indexed %d courses....\n", course_index->size);
}

int get_index_by_code_course_index(char *code_key) {
    struct course *search = init_course();
    strncpy(search->code, code_key, 16);
    xstrupr(search->code);
    return search_course_index(search, COURSE_CODE, 0, course_index->size);
}

struct course *get_by_code_course_index(char *code_key) {
    int index = get_index_by_code_course_index(code_key);
    if (!(index == -1)) {
        return course_index->c[index];
    }
    return NULL;
}

struct course *get_by_id_course_index(long id_key) {
    struct course *search = init_course();
    search->id = id_key;
    int index = search_course_index(search, COURSE_ID, 0, course_index->size);
    return index == -1 ? NULL : course_index->c[index];
}
