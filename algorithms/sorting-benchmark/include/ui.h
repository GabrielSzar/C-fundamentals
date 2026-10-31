#include "types.h"
#ifndef INTERFACE_H
#define INTERFACE_H
void print_result(BenchResult result, char* algo, State state);
void print_menu(char* options[], int n, int selected);
void print_header(State state);
void wait_screen(char* algo);
#endif
