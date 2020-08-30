COPS = -Wall -Wextra -Werror
BUILD_DIR = build

all: exec
clean: 
	rm -rf $(BUILD_DIR) exec


# '<' for current dependency, '@' for current target
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	gcc -g -c $< -o $@ 

C_FILES = $(wildcard *.c)
OBJ_FILES = $(C_FILES:%.c=$(BUILD_DIR)/%.o)

exec: $(OBJ_FILES)
	gcc -o exec $(OBJ_FILES)
