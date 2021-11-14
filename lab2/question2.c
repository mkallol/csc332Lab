
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int a = 10, b = 25, fq = 0, fr = 0, status;
    fq = fork(); //fork q
    if (fq == 0)
    {
        a = a + b;
        printf("a: %d, b: %d, pid: %d\n", a, b, getpid());
        fr = fork(); //fork r
        if (fr != 0)
        {
            b = b + 15;
            printf("a: %d, b: %d, pid: %d\n", a, b, getpid());
        }
        else
        {
            a = (a * b) + 20;
            printf("a: %d, b: %d, pid: %d\n", a, b, getpid());
        }
    }
    else
    {
        b = a + b - 5;
        printf("a: %d, b: %d, pid: %d\n", a, b, getpid());
    }

    waitpid(fq, &status, 0);
    waitpid(fr, &status, 0);
    return 0;
}