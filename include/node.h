#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;