#include "../include/linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty();
size_t size();
void print();
void print_file(FILE* stream);
void clear();
Node* append_left(size_t n, char new_data[n]);
Node* insert_after(Node* cur_node, Node* new_node);
Node* append(size_t n, char new_data[n]);
Node* delete_node(Node* cur_node);
Node* delete(char* data);
Node* get_node(size_t index);
Node* first();
Node* last();
Node* next();
Node* prev();
