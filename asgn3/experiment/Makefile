.DEFAULT_GOAL := all

CC := gcc

CFLAGS := -Wall -O3

TARGET := exp

SRC_PATH := src
OBJ_PATH := obj

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c)))
OBJ := $(foreach x, $(SRC), $(OBJ_PATH)/$(notdir $(basename $(x))).o)

.PHONY : all

all : clean $(TARGET)

$(TARGET) : obj
	$(CC) $(CFLAGS) -o $@ $(OBJ)

.PHONY: obj

obj : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	@mv *.o $(OBJ_PATH)

clean :
	rm -f $(TARGET)
	rm -f $(OBJ)


