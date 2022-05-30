#include "../include/linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty();
size_t size();
void print() {
    printf("LinkedList [ ");
    _cur_node = _head;
    while ( _cur_node != _tail ) {
        printf("%s ", _cur_node->data);
        _cur_node = next();
    }
    printf("%s ]\n", _cur_node->data);
}
void print_file(FILE* stream);
void clear();
Node* append_left(size_t n, char new_data[n]);
Node* insert_after(Node* cur_node, Node* new_node);
Node* append(size_t n, char new_data[n]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char)*n);
    strcpy(newNode->data, new_data);
    if (_cur_node == NULL)  // first add
        _head = _tail = newNode; // head, tail modified
    else {
        _cur_node->next = newNode;
        newNode->prev = _cur_node;
        _tail = newNode;
    }
    _cur_node = newNode;
    return newNode;
}
Node* delete_node(Node* cur_node);
Node* delete(char* data);
Node* get_node(size_t index);
Node* first() {
    return _head;
}
Node* last() {
    return _tail;
}
Node* next() {
    return _cur_node->next;
}
Node* prev() {
    return _cur_node->prev;
}
