CC   := gcc
STD  := -std=gnu17
WARN := -Wall -Wextra
INC  := -Iinclude

SRCS := $(wildcard main.c) $(wildcard algorithms-impl/*.c) $(wildcard benchmark/*.c) $(wildcard interface/*.c)

REL_CFLAGS := $(STD) $(WARN) $(INC) -O2 -DNDEBUG
REL_BUILD  := build/release
REL_OBJS   := $(SRCS:%.c=$(REL_BUILD)/%.o)

DBG_CFLAGS := $(STD) $(WARN) $(INC) -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer
DBG_BUILD  := build/debug
DBG_OBJS   := $(SRCS:%.c=$(DBG_BUILD)/%.o)

all: bench

bench: $(REL_OBJS)
	$(CC) $(REL_CFLAGS) $^ -o $@

debug: bench_debug

bench_debug: $(DBG_OBJS)
	$(CC) $(DBG_CFLAGS) $^ -o $@

$(REL_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(REL_CFLAGS) -MMD -MP -c $< -o $@

$(DBG_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(DBG_CFLAGS) -MMD -MP -c $< -o $@

-include $(REL_OBJS:.o=.d) $(DBG_OBJS:.o=.d)

clean:
	rm -rf build bench bench_debug

.PHONY: all debug clean
