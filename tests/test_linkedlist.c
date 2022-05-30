#include "gtest/gtest.h"
#include "linkedlist.h"
#include "node.h"
#include "textfilewriter.h"

class TestLinkedList : public ::testing::Test {
protected:
TestLinkedList() = default;
~TestLinkedList() = default;
virtual void SetUp() override {
printf("SetUp!");
int NUM_OF_MUSIC = 3;
music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
for (int i=0; i < NUM_OF_MUSIC; i++){
music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
}
music_titles[0] = (char*)"Hello";
music_titles[1] = (char*)"Enemy";
music_titles[2] = (char*)"abc";
}

virtual void TearDown() override {
printf("TearDown!");
clear();
music_titles = nullptr;
}

char** music_titles = nullptr;

};


TEST(TestLinkedList, Empty) {
    //empty_testcase
    Node* node = first_node();
    EXPECT_EQ(node, nullptr);
    EXPECT_EQ(empty(), true);
}

TEST(TestLinkedList, EmptySize) {
    //size_testcase
    size_t s = size();
    EXPECT_EQ(s, 0u);
}

TEST(TestLinkedList, Clear){
    //clear_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    clear();
    EXPECT_EQ(empty(),true);
}

TEST(TestLinkedList, InsertOne) {
    //append_testcase_1
    char* music_title = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    append(1, music_title);
    EXPECT_EQ(size(), 1u);
    clear();
}

TEST(TestLinkedList, RemoveOne) {
    //remove_testcase_1
    char* music_title = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    append(1, music_title);
    delete_by_data(music_title);
    EXPECT_EQ(size(), 0u);
    clear();
}

TEST(TestLinkedList, Insert_after){
   int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    strcpy(newNode->data,"insert");
    append(sizeof(music_titles[0]), music_titles[0]);
    Node* cur_node = append(sizeof(music_titles[1]), music_titles[1]);
    insert_after(cur_node, newNode);
    append(sizeof(music_titles[2]), music_titles[2]);
    EXPECT_EQ(size(),4);
    clear();
}

TEST(TestLinkedList, Delete_node){
    //deleteNode_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    Node* cur_node = append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    delete_node(cur_node);
    EXPECT_EQ(size(),2);
    clear();
}

TEST(TestLinkedList, InsertAndRemoveTitles) {
    //insertAndremove_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    EXPECT_EQ(size(), 3u);
    EXPECT_EQ(empty(), false);
    delete_by_data(music_titles[0]);
    EXPECT_EQ(size(), 2u);
    EXPECT_EQ(empty(), false);
    delete_by_data(music_titles[1]);
    EXPECT_EQ(size(), 1u);
    EXPECT_EQ(empty(), false);
    delete_by_data(music_titles[2]);
    EXPECT_EQ(size(), 0u);
    EXPECT_EQ(empty(), true);
    clear();
}

TEST(TestLinkedList, Append) {
//append_testcase_2
int NUM_OF_MUSIC = 3;
char** music_titles = NULL;
music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
for (int i=0; i < NUM_OF_MUSIC; i++){
music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
}
music_titles[0] = (char*)"Hello";
music_titles[1] = (char*)"Enemy";
music_titles[2] = (char*)"abc";
append(sizeof(music_titles[0]), music_titles[0]);
append(sizeof(music_titles[1]), music_titles[1]);
append(sizeof(music_titles[2]), music_titles[2]);
EXPECT_STREQ(first_node()->data, music_titles[0]);
EXPECT_STREQ(last_node()->data, music_titles[2]);
clear();
}

TEST(TestLinkedList, AppendLeft) {
//append_left_testcase
int NUM_OF_MUSIC = 3;
char** music_titles = NULL;
music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
for (int i=0; i < NUM_OF_MUSIC; i++){
music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
}
music_titles[0] = (char*)"Hello";
music_titles[1] = (char*)"Enemy";
music_titles[2] = (char*)"abc";
append_left(sizeof(music_titles[0]), music_titles[0]);
append_left(sizeof(music_titles[1]), music_titles[1]);
append_left(sizeof(music_titles[2]), music_titles[2]);
EXPECT_STREQ(first_node()->data, music_titles[2]);
EXPECT_STREQ(last_node()->data, music_titles[0]);
clear();
}


TEST(TestLinkedList, NextAndPrev) {
    //next,prev_testcase
     int NUM_OF_MUSIC = 3;
     char** music_titles = NULL;
     music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
     for (int i=0; i < NUM_OF_MUSIC; i++){
         music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
     }
     music_titles[0] = (char*)"Hello";
     music_titles[1] = (char*)"Enemy";
     music_titles[2] = (char*)"abc";
    append_left(sizeof(music_titles[0]), music_titles[0]);
    Node* cur_node = append_left(sizeof(music_titles[1]), music_titles[1]);
    EXPECT_STREQ(cur_node->data, music_titles[1]);
    cur_node = next();
    EXPECT_STREQ(cur_node->data, music_titles[0]);
    cur_node = append(sizeof(music_titles[2]), music_titles[2]);
    EXPECT_STREQ(cur_node->data, music_titles[2]);
    cur_node = prev();
    EXPECT_STREQ(cur_node->data, music_titles[1]);
    clear();
}

TEST(TestLinkedList, GetNode){
//getNode_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    Node* getN = get_node(1);
    EXPECT_STREQ(getN->data,music_titles[1]);
    clear();
}

TEST(TestLinkedList, First_NodeAndLast_Node){
    //firstNode,lastNode_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    Node* testFirst = first_node();
    Node* testLast = last_node();
    EXPECT_STREQ(testFirst->data, music_titles[0]);
    EXPECT_STREQ(testLast->data, music_titles[2]);
    clear();
}

TEST(TestLinkedList, FindNode){
    //FindNode_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    Node* temp = find_node(music_titles[1]);
    EXPECT_STREQ(temp->data, music_titles[1]);
    temp = find_node(music_titles[2]);
    EXPECT_STREQ(temp->data, music_titles[2]);
    temp = find_node(music_titles[0]);
    EXPECT_STREQ(temp->data, music_titles[0]); 
    clear();
}

TEST(TestLinkedList, PopLeft){
    //pop_left_testcase
    int NUM_OF_MUSIC = 3;
    char** music_titles = NULL;
    music_titles = (char**)malloc(sizeof(char*) * NUM_OF_MUSIC);
    for (int i=0; i < NUM_OF_MUSIC; i++){
        music_titles[i] = (char*)malloc(sizeof(char) * MAX_TITLE_SIZE);
    }
    music_titles[0] = (char*)"Hello";
    music_titles[1] = (char*)"Enemy";
    music_titles[2] = (char*)"abc";
    append(sizeof(music_titles[0]), music_titles[0]);
    append(sizeof(music_titles[1]), music_titles[1]);
    append(sizeof(music_titles[2]), music_titles[2]);
    Node* temp = pop_left(); 
    EXPECT_STREQ(temp->data, music_titles[0]);
    free(temp->data);
    free(temp);
    EXPECT_EQ(size(),2);
    clear();
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::AddGlobalTestEnvironment(new LinkedListEnvironment);
    return RUN_ALL_TESTS();
}
