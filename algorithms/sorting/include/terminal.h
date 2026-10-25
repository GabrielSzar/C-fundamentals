#ifndef TERMINAL_H
#define TERMINAL_H

int enable_cbreak_mode(void);
int restore_terminal(void);
void disable_cbreak_mode(void);
void handler_dis_cbreak(int sig);
void enable_sig_handler(void);
#endif
