#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
    struct termios original = { 0 };
    struct termios work = { 0 };
    tcgetattr(STDIN_FILENO, &original);
    tcgetattr(STDIN_FILENO, &work);
    work.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &work);
    while (1) {
        int input = getchar();
        printf("%i\n", input);
        if (input == 113) {
            break;
        }
    };
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}
