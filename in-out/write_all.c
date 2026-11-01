#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int write_all_rec(int fd, const unsigned char* buf, size_t n)
{
    ssize_t n_bytes = write(fd, buf, n);
    if (n_bytes == -1 && errno == EINTR) {
        return write_all_rec(fd, buf, n);
    }
    if (n_bytes <= 0) {
        return -1;
    }
    if (n_bytes == n) {
        return 0;
    }
    return write_all_rec(fd, &buf[n_bytes], n - n_bytes);
}
int write_all(int fd, const unsigned char* buf, size_t n)
{
    const unsigned char* lasting_buf = buf;
    size_t lasting_n_bytes = n;
    while (lasting_n_bytes != 0) {
        ssize_t n_bytes = write(fd, lasting_buf, 1);
        if (n_bytes == -1 && errno == EINTR) {
            continue;
        }
        if (n_bytes <= 0) {
            return -1;
        }
        lasting_n_bytes -= n_bytes;
        lasting_buf = &lasting_buf[n_bytes];
    }
    return 0;
}

int main(void)
{
    unsigned char* string = (unsigned char*)"Hello,World!";
    if (write_all(STDOUT_FILENO, string, strlen((char*)string)) == -1) {
        perror("error while writing");
        exit(EXIT_FAILURE);
    }
}
