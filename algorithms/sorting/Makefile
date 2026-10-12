CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -g -Iinclude
BUILD   := build

SRCS := $(wildcard src/*.c) $(wildcard benchmark/*.c)
OBJS := $(SRCS:%.c=$(BUILD)/%.o)

bench: $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) bench

.PHONY: clean
