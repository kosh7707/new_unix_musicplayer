GTEST_DIR=googletest/googletest

USER_DIR=.
TEST_DIR=tests
LIB_DIR=libs
OBJ_DIR=objs
SRC_DIR=src
EXEC_DIR=bin
BUILD_DIR=build
INCLUDE_DIR=include

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

TESTS  = test_player
SRCS  := $(wildcard $(TEST_DIR)/*.c)
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
LIBS  := $(wildcard $(LIB_DIR)/*.c)
OBJS  := $(LIBS:$(LIB_DIR)/%.c=$(BUILD_DIR)/$(OBJ_DIR)/%.o) 
TARGET := MusicPlayer

EXECS := $(SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/$(EXEC_DIR)/%)

BUILD_SUB_DIR := $(OBJ_DIR) $(EXEC_DIR)
MAKE_DIR := $(BUILD_DIR) $(BUILD_SUB_DIR:%=$(BUILD_DIR)/%)
$(info OBJS $(OBJS) EXECS $(EXECS))
$(info MAKE_DIR $(MAKE_DIR) HEADERS $(HEADERS))

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : build_dir $(EXECS) $(BUILD_DIR)/$(TARGET)

clean :
	rm -rf $(EXECS) gtest.a gtest_main.a *.o $(BUILD_DIR)

test :
	$(EXECS)

$(BUILD_DIR)/$(TARGET) : $(OBJS) $(SRC_DIR)/Player.c
	$(CXX) $^ -o $@

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/$(OBJ_DIR)/gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/$(OBJ_DIR)/%.o : $(LIB_DIR)/%.c
	$(CXX) $(CPPFLAGS) -I$(INCLUDE_DIR) $(CXXFLAGS) -c $^ -o $@

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(GTEST_HEADERS) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

build_dir : |$(MAKE_DIR)

$(MAKE_DIR):
	mkdir -p $(MAKE_DIR)

$(EXECS) : $(SRCS) $(OBJS) $(HEADERS) gtest-all.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(INCLUDE_DIR) -lpthread $^ -o $@
