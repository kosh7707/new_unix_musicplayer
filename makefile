CC := gcc
TARGET := MusicPlayer
BUILD := build
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs

.PHONY: clean all

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(BUILD)/Player.o
	$(CC) -o $@ $^

$(BUILD)/textfilewriter.o: $(LIBS_DIR)/textfilewriter.c $(INCLUDE_DIR)/textfilewriter.h
	$(CC) -o $@ $^

$(BUILD)/linkedlist.o: $(LIBS_DIR)/linkedlist.c $(INCLUDE_DIR)/linkedlist.h $(INCLUDE_DIR)/node.h
	$(CC) -o $@ $^

$(BUILD)/Player.o: $(BUILD)/linkedlist.o $(BUILD)/textfilewriter.o
	$(CC) -o $@ $^

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -rf build


