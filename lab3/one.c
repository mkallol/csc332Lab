#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    if (pid == 0)
    { // Child case
        printf("Child PID: %d\n", getpid());
        execl("/bin/date", "date", NULL);
    }
    else
    { // Parent case
        wait(NULL);
        printf("Parent PID: %d\n", getpid());
    }
    return 0;
}