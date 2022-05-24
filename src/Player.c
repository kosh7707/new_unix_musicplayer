#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedlist.h"
#include "../include/textfilewriter.h"

int main() {
    int N; scanf("%d", &N);
    Node* nodes = malloc(sizeof(Node) * N);
    for(int i=0; i<N; i++) {
        nodes[i].data = (char*)malloc(sizeof(char*));
        scanf("%s", nodes[i].data);
    }
    for(int i=0; i<N; i++) {
        printf("%s\n", nodes[i].data);
    }

    // memory dealloc
    for(int i=0; i<N; i++) {
        free(nodes[i].data);
    }
    free(nodes);
    return 0;
}