#include "linkedlist.h"
#include "textfilewriter.h"
#include <string.h>

void getCommand(char* command) {
    if (strcmp(command, "add") == 0) {
		char temp_data[100];
        scanf("%s", temp_data);
        append_left(100, temp_data);

    } else if (strcmp(command, "del") == 0) {
        // del (str) --> 재생 목록에서 해당 노래명을 삭제함
        // need delete_by_data()

    } else if (strcmp(command, "list") == 0) {
        print();
        
    } else if (strcmp(command, "next") == 0) {
        // 재생 목록의 다음 노래로 이동함
        // need next()
        

    } else if (strcmp(command, "prev") == 0) {
        // 재생 목록의 이전 노래로 이동함
        // need prev()

    } else if (strcmp(command, "move") == 0) {
        // move (int) --> 현재 노래를 (int)의 다음 위치로 이동시킴
        // 가->나->다->라 에서 현재가 '나' 일때 move 4 하면 가->다->라->나
        // need get_node(), insert_after()

    } else if (strcmp(command, "play") == 0) {
        // 노래를 재생함 --> [노래명] is now playing!
        // need get_node()

    } else if (strcmp(command, "clear") == 0) {
        // 재생 목록을 비움 --> LinkedList is cleared!
        // need clear()

    } else if (strcmp(command, "quit") == 0) {
        // clear를 실행 후 뮤직 플레이어를 종료함 --> quit!
        // need clear()

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
    while (N --> 0) {
        char command[100];
        scanf("%s", command);
		getCommand(command);
    }
    return 0;
}
