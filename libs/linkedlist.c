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



Node* append_left(size_t n, char new_data[n]){
	//재생 목록의 첫 번째 위치에 노래를 추가함
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->prev = NULL;
    newNode->next = NULL;
    //printf("%s\n", newNode->data);
    if(empty()){
        _head = newNode;
        _tail = newNode;
    }
    else {
        newNode->next = _head;
        _head->prev = newNode;
        _head = newNode;
    }
    //printf("%s\n", _head->data);
    return newNode;	
};



Node* insert_after(Node* cur_node, Node* new_node);



Node* append(size_t n, char new_data[n]) {
        //연결 리스트 마지막에 노드추가
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(empty()){
        _head = newNode;
        _tail = newNode;
    }
    else{
        _tail->next = newNode;
        newNode->prev = _tail;
        _tail = newNode;
    }
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
