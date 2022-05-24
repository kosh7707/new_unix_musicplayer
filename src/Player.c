#include <stdio.h>
#include "../include/linkedlist.h"
#include "../include/textfilewriter.h"

int main() {
    int N; scanf("%d", &N);
    while (N --> 0) {
        char temp_data[100];
        scanf("%s", temp_data);
        append(100, temp_data);
    }

    print();

    return 0;
}