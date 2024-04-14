.DEFAULT_GOAL := all

CC := g++
CFLAGS := -Wall -Wextra --pedantic

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := include

TARGET := cacheSim

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(foreach x, $(SRC), $(OBJ_PATH)/$(notdir $(basename $(x))).o)
INC := $(foreach x, $(INC_PATH), $(wildcard $(addprefix $(x)/*,.h*)))

.PHONY: all
all : $(TARGET)

$(TARGET) : obj
	$(CC) $(CFLAGS) -o $@ $(OBJ)

.PHONY: obj
obj : $(SRC) $(INC)
	$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(OBJ_PATH)


clean :
	rm -f $(TARGET)
	rm -f $(OBJ)
