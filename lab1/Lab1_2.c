#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char text[fd];

    //open the file
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error: the file either doesn't exist or doesn't have read permission \n");
        return 0;
    }
    else
    {
        //read file
        read(fd, text, 10000);
        write(1, text, 10000);
    }

    close(fd);

    return 0;
}
