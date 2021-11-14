#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd;
    if (2 != argc)
    {
        printf("\nUsage: \n");
    }
    errno = 0;
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1)
    {
        printf("\nopen() failed with error %s \n", strerror(errno));
        perror("open");
    }
    else
    {
        printf("\n open() successfull \n");
    }
    close(fd);
    return 0;
}
