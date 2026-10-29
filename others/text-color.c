#include "ANSI_Color.h"
#include <stdio.h>

#define FOREGROUND 3
#define BACKGROUND 4
// this is the array version of the 3 bits(0-7) basic color wheel.
// the #define is on ANSI_Color.h
const char* COLOR[] = {
    "\x1b[30m",
    "\x1b[31m",
    "\x1b[32m",
    "\x1b[33m",
    "\x1b[34m",
    "\x1b[35m",
    "\x1b[36m",
    "\x1b[37m",
    "\x1b[0m",
};
typedef enum {
    C_BLACK,
    C_RED,
    C_GREEN,
    C_YELLOW,
    C_BLUE,
    C_MAGENTA,
    C_CYAN,
    C_WHITE,
    C_RESET_COLOR,
} COLOR_CODE;

// Call with macros FOREGROUND OR BACKGROUND
int print_colors(int layer)
{
    if (layer != 3 && layer != 4) {
        printf("Wrong Layer Code\n");
        return -1;
    }
    for (int i = 0; i < 256; i++) {
        printf("\x1b[%i8;5;%im Color with code: %i %s\n", layer, i, i, RESET_COLOR);
    }
    return 1;
}
// Call with macros FOREGROUND OR BACKGROUND
int print_RGB(int layer)
{
    if (layer != 3 && layer != 4) {
        printf("Wrong Layer Code\n");
        return -1;
    }
    for (int r = 0; r < 256; r++) {
        for (int g = 0; g < 256; g++) {
            for (int b = 0; b < 256; b++) {
                printf("\x1b[%i8;2;%i;%i;%im RGB Colors!!! RED: %i GREEN: %i BLUE: %i %s\n", layer, r, g, b, r, g, b, RESET_COLOR);
            }
        }
    }
    return 1;
}

int main(void)
{
    print_RGB(FOREGROUND);
}
