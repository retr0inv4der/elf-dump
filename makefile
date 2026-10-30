
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

SRC := $(SRC_DIR)/main.c $(SRC_DIR)/elf_file.c
OBJ := $(BUILD_DIR)/main.o $(BUILD_DIR)/elf_file.o

.PHONY: all clean

all: app

app: $(OBJ)
	@echo "Linking object files..."
	@gcc $(OBJ) -o $(BUILD_DIR)/app

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c | $(BUILD_DIR)
	@echo "Compiling main.c..."
	@gcc -Wall -Wextra -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/elf_file.o: $(SRC_DIR)/elf_file.c | $(BUILD_DIR)
	@echo "Compiling elf_file.c..."
	@gcc -Wall -Wextra -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ) $(BUILD_DIR)/app
