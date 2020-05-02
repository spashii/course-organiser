#include "course_index.h"

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include "../course/course.h"
#include "../course_list/course_list.h"

struct course **course_index;

void init_course_index(struct course_list *l) {
    course_index = (struct course **)malloc(sizeof(struct course *) * (l->size));
}

void make_course_index(struct course_list *l){
    init_course_index(l);
    int i = 0;
    struct course_list_node *trav = l->head;
    for (i = 0; i < l->size; i++) {
        course_index[i] = trav->data;
        trav = trav->next;
    }
    // qsort(course_index, l->size, sizeof(struct course *), compare_course_code);
    // qs_course_index(course_index, 0, l->size);
}

int qs_partition_course_index(struct course **arr, int low, int high) {
    struct course *pivot = arr[high];
    int i = low - 1;
    int j = low;
    for (; j <= high - 1; j++) {
        if (strncmp(arr[j]->code, pivot->code, 16) < 0){
            i++;
            qs_swap_course_index(&arr[i], &arr[j]);
        }
    }
    qs_swap_course_index(&arr[i + 1], &arr[high]);
    return i + 1;
}

int qs_partition_r_course_index(struct course **arr, int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);
    qs_swap_course_index(&arr[random], &arr[high]);
    return qs_partition_course_index(arr, low, high);
}

void qs_course_index(struct course **arr, int low, int high){
    if (low<high){
        int pi = qs_partition_r_course_index(arr, low, high);
        qs_course_index(arr, low, pi - 1);
        qs_course_index(arr, pi + 1, high);
    }
}

void qs_swap_course_index(struct course **a, struct course **b){
    // struct course *save = malloc(sizeof(struct course));
    // memcpy(save, a   , sizeof(struct course));
    // memcpy(a   , b   , sizeof(struct course));
    // memcpy(b   , save, sizeof(struct course));
    // free(save);
    struct course *save = *a;
    *a = *b;
    *b = save;
}

