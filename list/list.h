#ifndef _LIST_H_
#define _LIST_H_

struct list_node {
  void* data;
  struct node* next;
};

struct list_node* init_list_node(void* ptr);

struct list {
    struct node * head;
};

struct list* init_list();
void insert_list(struct list *l, void *data, size_t data_size);

#endif