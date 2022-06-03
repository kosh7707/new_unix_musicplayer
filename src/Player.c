#include "linkedlist.h"
#include "textfilewriter.h"
#include <string.h>

int last_node_idx = 0;
int cur_node_idx = 0;
int stop = 0;

void getCommand(char* command) {
	last_node_idx = size();
    if (strcmp(command, "add") == 0) {
		char temp_data[100];
        scanf("%s", temp_data);
        append_left(100, temp_data);

    } else if (strcmp(command, "del") == 0) {
        char temp_data[100];
        scanf("%s", temp_data);
        delete_by_data(temp_data);

    } else if (strcmp(command, "list") == 0) {
        print();
        
    } else if (strcmp(command, "next") == 0) {
    	if (cur_node_idx < last_node_idx - 1) cur_node_idx++;
        next();
        
    } else if (strcmp(command, "prev") == 0) {
    	if (cur_node_idx > 0) cur_node_idx--;
		prev();
		
    } else if (strcmp(command, "move") == 0) {
        int temp_2;
        scanf("%d", &temp_2);
        Node* new_node = get_node(cur_node_idx);
        delete_node(new_node);
        insert_after(get_node(temp_2-2), new_node);
        cur_node_idx = temp_2-1;

    } else if (strcmp(command, "play") == 0) {
        Node* temp_node = get_node(cur_node_idx);
        printf("%s is now playing!\n", temp_node->data);
		
    } else if (strcmp(command, "clear") == 0) {
		clear();
		cur_node_idx = 0;
		last_node_idx = 0;
		
    } else if (strcmp(command, "quit") == 0) {
        stop = 1;
        clear();
        printf("quit!\n");
        
    } else if (strcmp(command, "load") == 0) {
        // 파일에 저장된 내용을 읽고 재생 목록을 생성함
        // need read_file()

    } else if (strcmp(command, "save") == 0) {
        // 재생 목록의 노래명을 역순으로 파일에 저장함.
        // 3\n Hello\n Enemy\n abc
        // need write_file()

    } else {
        printf("Invalid command\n");
    }
}

int main() {
    int N; scanf("%d", &N);
    while (N --> 0) {
        char temp_data[100];
        scanf("%s", temp_data);
        append(100, temp_data);
    }
    scanf("%d", &N);
    while (N --> 0 && stop != 1) {
        char command[100];
        scanf("%s", command);
		getCommand(command);
    }
    return 0;
}
