#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    if (pid == 0)
    { // Child case
        printf("Child PID: %d\n", getpid());
        char *argv[] = {"ls", "-laxo", NULL};
        execvp(argv[0], argv);
        printf("EXECVP Failed\n");
    }

    else
    { // Parent case
        wait(NULL);
        printf("Parent PID: %d\n", getpid());
    }
    return 0;
}