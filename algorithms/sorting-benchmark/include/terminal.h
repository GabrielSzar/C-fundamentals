#ifndef TERMINAL_H
#define TERMINAL_H

typedef enum {
    KEY_UP,
    KEY_DOWN,
    KEY_ENTER,
    KEY_QUIT,
    KEY_OTHER,
    KEY_ERROR,
} Keys;

int enable_cbreak_mode(void);
void restore_terminal(void);
int copy_attributes(void);
Keys read_input(void);
void disable_cbreak_mode(void);
void handler_dis_cbreak(int sig);
void enable_sig_handler(void);
void clear(void);
#endif
