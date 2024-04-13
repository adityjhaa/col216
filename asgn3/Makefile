.DEFAULT_GOAL := all

CC := g++
CFLAGS := -Wall -Wextra --pedantic

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := include

TARGET := cacheSim

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(foreach x, $(OBJ_PATH), $(wildcard $(addprefix $(x)/*,.o)))
INC := $(foreach x, $(INC_PATH), $(wildcard $(addprefix $(x)/*,.h*)))

all : $(TARGET)

$(TARGET) : obj
	$(CC) -o $@ $(OBJ) $(CFLAGS)


obj : $(SRC) $(INC)
	$(CC) -c $(SRC) $(CFLAGS)
	@mv *.o $(OBJ_PATH)


clean :
	rm -f $(TARGET)
	rm -f $(OBJ)
