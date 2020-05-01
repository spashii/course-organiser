#include "list.h"

#include <malloc.h>
#include <stdio.h>

struct list_node* init_list_node(void* ptr) {
    struct list_node* new = (struct list_node*)malloc(sizeof(struct list_node));
    new->data = NULL;
    new->next = NULL;
    return new;
}

struct list* init_list() {
    struct list* new = (struct list*)malloc(sizeof(struct list));
    new->head = NULL;
}

void insert_list(struct list* l, void* data, size_t data_size) {
    struct list_node* insert = init_list_node(data);
    if (l->head == NULL) {
        l->head = insert;
    } else {
        void* save = l->head;
        insert->next = save;
        l->head = insert;
    }
}

void print_list(struct list* l) {
    struct list_node* trav = l->head;
    while (trav) {
        printf("%p", trav->data);
        trav = trav->next;
    }
}