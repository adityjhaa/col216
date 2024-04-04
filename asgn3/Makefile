.DEFAULT_GOAL := all

CC := g++
CFLAGS := -Wall -Wextra --pedantic

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := include

TARGET := cacheSim

SRC := $(wildcard $(SRC_PATH)/*.cpp)
OBJ := $(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRC))
INC := $(wildcard $(INC_PATH)/*.h*)

some :
	$(OBJ)


all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


$(OBJ) : $(SRC) $(INC)
	$(CC) -c $< -o $@ $(CFLAGS)


clean :
	rm -f $(TARGET)
	rm -f $(OBJ)
