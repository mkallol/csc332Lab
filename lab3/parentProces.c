
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t mypid = fork();

    if (mypid == 0)
    {
        char *p1 = "./Prcs_P1";
        printf("Child 1: executing %s\n", p1);
        sleep(2);
        execl(p1, p1, (char *)NULL);
    }

    //Wait for child 1 to finish and fork again;
    wait(NULL);
    printf("Child 1 terminated, parent is going to fork again.\n");
    sleep(2);
    mypid = fork();

    if (mypid == 0)
    {
        char *p2 = "./Prcs_P2";
        printf("Child 2: executing %s\n", p2);
        sleep(2);
        execl(p2, p2, (char *)NULL);
    }

    wait(NULL);
    printf("Child 2 terminated.\n");
    sleep(2);
    printf("Parent exiting.\n");

    exit(0);
}