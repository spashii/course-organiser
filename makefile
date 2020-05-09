OUT := app

INC_DIR := include
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC     := gcc
CFLAGS := -Wall -g -I$(INC_DIR)

all: dirs $(OUT)

dirs: 
	mkdir -p $(OBJ_DIR)
	mkdir -p database

$(OUT): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(OUT)

.PHONY: all clean dirs