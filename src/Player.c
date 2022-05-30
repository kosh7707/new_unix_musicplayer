#include "../include/linkedlist.h"
#include "../include/textfilewriter.h"

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
        if (strcmp(command, "add") == 0) {
            // add (str) --> 재생 목록의 첫 번째 위치에 노래를 추가함

        } else if (strcmp(command, "del") == 0) {
            // del (str) --> 재생 목록에서 해당 노래명을 삭제함

        } else if (strcmp(command, "list") == 0) {
            // 재생 목록을 출력함 --> LinkedList [ 노래명 노래명 노래명 ]
            print();
        } else if (strcmp(command, "next") == 0) {
            // 재생 목록의 다음 노래로 이동함

        } else if (strcmp(command, "prev") == 0) {
            // 재생 목록의 이전 노래로 이동함

        } else if (strcmp(command, "move") == 0) {
            // move (int) --> 현재 노래를 (int)의 다음 위치로 이동시킴
            // 가->나->다->라 에서 현재가 '나' 일때 move 4 하면 가->다->라->나

        } else if (strcmp(command, "play") == 0) {
            // 노래를 재생함 --> [노래명] is now playing!

        } else if (strcmp(command, "clear") == 0) {
            // 재생 목록을 비움 --> LinkedList is cleared!

        } else if (strcmp(command, "quit") == 0) {
            // clear를 실행 후 뮤직 플레이어를 종료함 --> quit!

        } else if (strcmp(command, "load") == 0) {
            // 파일에 저장된 내용을 읽고 재생 목록을 생성함

        } else if (strcmp(command, "save") == 0) {
            // 재생 목록의 노래명을 역순으로 파일에 저장함.
            // 3\n Hello\n Enemy\n abc

        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}