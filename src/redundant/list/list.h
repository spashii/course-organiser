#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

struct list_node {
    void* data;
    struct list_node* next;
};

struct list_node* init_list_node(void* data, size_t data_size);

struct list {
    struct list_node* head;
};

struct list* init_list();
void insert_list(struct list* l, void* data, size_t data_size);

#endif