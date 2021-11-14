#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define BUFF_SIZE 100

int main(int argc, char *argv[])

{
    int fd;

    fd = open(argv[1], O_RDONLY);

    int nd;
    nd = open("destination", O_RDWR);

    char text[BUFF_SIZE];

    if (fd != -1 || nd != -1)
    {

        read(fd, text, sizeof(text) - 1);
        lseek(1, 0, SEEK_END);
        write(4, text, sizeof(text) - 1);
        printf("\n file is copied to the destination file. \n \n");
        close(fd);
        close(nd);
    }
    return 0;
}