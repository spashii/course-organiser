#include "list.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

struct list_node* init_list_node(void* data, size_t data_size) {
    struct list_node* new = (struct list_node*)malloc(sizeof(struct list_node));
    new->data = malloc(data_size);
    memcpy(new->data, data, data_size);
    new->next = NULL;
    return new;
}

struct list* init_list() {
    struct list* new = (struct list*)malloc(sizeof(struct list));
    new->head = NULL;
    return new;
}

void insert_list(struct list* l, void* data, size_t data_size) {
    struct list_node* insert = init_list_node(data, data_size);
    struct list_node* save = l->head;
    insert->next = save;
    l->head = insert;
}