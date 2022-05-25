CC := gcc
TARGET := MusicPlayer
BUILD := build
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs

$(BUILD)/textfilewriter.o: $(LIBS_DIR)/textfilewriter.c $(INCLUDE_DIR)/textfilewriter.h
	$(CC) -c $< -o $@

$(BUILD)/linkedlist.o: $(LIBS_DIR)/linkedlist.c $(INCLUDE_DIR)/linkedlist.h $(INCLUDE_DIR)/node.h
	$(CC) -c $< -o $@

$(BUILD)/$(TARGET): $(SRC_DIR)/Player.c $(BUILD)/linkedlist.o $(BUILD)/textfilewriter.o
	$(CC) $^ -o $@

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -rf build


