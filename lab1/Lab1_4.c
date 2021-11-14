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
    nd = open("test.txt", O_RDWR);

    char text[BUFF_SIZE];

    if (fd != -1 || nd != -1)
    {

        read(fd, text, 100);
        int i = 0;
        while (text[i] != EOF)
        {
            if (text[i] == '1')
                text[i] = 'L';
            i++;
        }
        lseek(1, 0, SEEK_END);
        write(4, text, 100);
        close(fd);
        close(nd);
    }
    return 0;
}