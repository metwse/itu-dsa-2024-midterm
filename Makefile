CC = gcc
DEBUGGER = gdb

SRC_DIR = solutions
BUILD_DIR = target
OBJ_DIR = $(BUILD_DIR)/build

CFLAGS=-O2 -Wall -Werror -std=c99
TFLAGS=-O0 -g3 -Wall -std=c99 -D_DEBUG

# Detect files
MODULE_SRCS = $(wildcard $(SRC_DIR)/module_*.c)
SOLUTION_SRCS = $(wildcard $(SRC_DIR)/q*.c)

# Object paths
MODULE_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(MODULE_SRCS))
MODULE_DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.debug.o,$(MODULE_SRCS))

# Pattern rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.debug.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(TFLAGS) $< -o $@

# Per-question rules
define Q_RULES

$(BUILD_DIR)/$(1): $(OBJ_DIR)/$(1).o $(MODULE_OBJS)
	$(CC) $$^ -o $$@

$(BUILD_DIR)/$(1).debug: $(OBJ_DIR)/$(1).debug.o $(MODULE_DEBUG_OBJS)
	$(CC) $$^ -o $$@

.PHONY: $(1) debug_$(1)

$(1): $(BUILD_DIR)/$(1)
debug_$(1): $(BUILD_DIR)/$(1).debug

endef

# Generate q1, q2, ... rules
$(foreach f,$(basename $(notdir $(SOLUTION_SRCS))),$(eval $(call Q_RULES,$(f))))

# Folder creation
$(OBJ_DIR): | $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean

run_%: %
	$(BUILD_DIR)/$(subst run_,,$@)

run_debug_%: debug_%
	$(DEBUGGER) $(BUILD_DIR)/$(subst run_debug_,,$@).debug


clean:
	rm -rf $(BUILD_DIR)
