#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty(){
    if(_head == NULL) return true;
    else return false;
}

size_t size() {
    //linked_list 원소의 개수
    Node* temp = _head;
    int size = 0;
    if(empty()) return size;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}

void print(){
    //재생목록을 콘솔에 출력함
    Node* temp = _head;
    printf("LinkedList [ ");
    while(temp != NULL){
        printf("%s ",temp->data);
        temp = temp->next;
    }
    printf("]\n");	
}

void print_file(FILE* stream){
    if(stream == NULL) return;
    char buffer[1000]={0,};
    fread(buffer,1,sizeof(buffer),stream);
    printf("%s",buffer);
    fclose(stream);
}

void clear(){
    //재생 목록을 비움
    Node* temp = _head;
    while(temp != NULL){
        temp = temp->next;
        free(_head->data);
        free(_head);
        _head = temp;
    }
    printf("LinkedList is cleared!\n");
}

Node* append_left(size_t n, char new_data[]){
    //재생 목록의 첫 번째 위치에 노래를 추가함
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char)*n);
    strcpy(newNode->data, new_data);
    newNode->prev = NULL;
    newNode->next = NULL;

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
    _cur_node = _head;
    return newNode;
}

Node* append(size_t n, char new_data[]){
    //연결 리스트 마지막에 노드추가
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char)*n);
    strcpy(newNode->data, new_data);
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
    _cur_node = _head;
    return newNode;
}

Node* insert_after(Node* cur_node, Node* new_node){
    if(cur_node->next == NULL){
        _tail = new_node;
    }
    new_node->next = cur_node->next;
	new_node->prev = cur_node;
	new_node->next->prev = new_node;
	cur_node->next = new_node;
	
    return new_node;

}

Node* pop_left(){
    //Delete first_node which is head
    Node* temp = _head;
    if(empty()) return temp; //return NULL
    if(_head == _tail){
        _head = NULL;
        _tail = NULL;
    }
    else{
        _head->next->prev = NULL;
        _head = _head->next;
    }
    //free(temp->data);
    //free(temp);
    return temp;
}

Node* pop(){
    //Delete last_node which is tail
    Node *temp = _tail;
    if(empty()) return temp; //return NULL
    if(_head == _tail){
        _head = NULL;
        _tail = NULL;
    }
    else{
        _tail->prev->next = NULL;
        _tail = _tail->prev;
    }
    //free(temp->data);
    //free(temp);
    return temp;
}

Node* delete_node(Node* cur_node){
    Node* temp = _head;
    if(empty()) return temp;
    else {
        while(temp != NULL){
            if(temp->data == cur_node->data){
                if(_head == _tail){
                    _head = NULL;
                    _tail = NULL;
                }
                else{
                    if(temp == _head) _head = temp->next;
                    else temp->prev->next = temp->next;
                    if(temp == _tail) _tail = temp->prev;
                    else temp->next->prev = temp->prev;
                }
                //printf("Delete data:%s\n",temp->data);
                return temp;
            }
            else temp = temp->next;
        }
    }
    //printf("Delete NULL\n");
    return temp;
}

Node* delete_by_data(char* data){
    //재생 목록에서 해당 노래명을 삭제함
    Node* temp = _head;
    if(empty()) return temp;//printf("empty\n");
    else{
        while(temp != NULL){
        	// use strcmp --> if equal return 0
            if(strcmp(temp->data, data) == 0){
                if(_head == _tail){
                    _head = NULL;
                    _tail = NULL;
                }
                else{
                    if(temp == _head) _head = temp->next;
                    else temp->prev->next = temp->next;
                    if(temp == _tail) _tail = temp->prev;
                    else temp->next->prev = temp->prev;
                }
                //printf("Delete data:%s\n",temp->data);
                free(temp);
                return temp;
            }
            else temp = temp->next;
        }
    }
    //printf("Delete NULL\n");
    return temp;
}

Node* next(){
    //재생 목록의 다음 노래로 이동함
    if(_cur_node->next != NULL) _cur_node = _cur_node->next;
    return _cur_node;
}

Node* prev(){
    //재생 목록의 이전 노래로 이동함
    if(_cur_node->prev != NULL) _cur_node = _cur_node->prev;
    return _cur_node;
}

Node* first_node(){
    return _head;
}

Node* last_node(){
    return _tail;
}

Node* get_node(size_t index){
    Node* temp = _head;
    size_t count = 0;
    if(size() == 0 || index > size()) return temp;

    while(temp != NULL){
        if(count == index) return temp;
        else {
            temp = temp->next;
            count++;
        }
    }
    return temp;
}

Node* find_node(char* data){
    Node* temp = _head;
    if(empty()) printf("Linkedlist is empty\n");
    else{
        //1~n n = 노드의 전체개수
        int index=1;
        while(temp != NULL){
	    if(strcmp(temp->data,data) == 0) {
                printf("node:%s position:%d\n", temp->data,index);
                return temp;
            }
            else {
                temp = temp->next;
                index++;
            }
        }
    }
    printf("Not Found\n");
    return temp;
};
