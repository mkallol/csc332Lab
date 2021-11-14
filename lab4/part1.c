// Moshahid Kallol
// Lab4  // Csc332

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char iput[100];
    char *token;

    printf("\nInterpreter: ");
    scanf(" %[^\n]s", iput); //interpreter takes the input

    while (strcmp(iput, "quit")) //returns 0 when both string's characters are equal ->>Exit
    {

        char *inputArray[10] = {NULL}; //taking a null array first
        token = strtok(iput, " ");     // converts string to smaller command strings untill space
        int i = 0;
        while (token != NULL)
        {
            inputArray[i++] = token;
            token = strtok(NULL, " ");
        }
        int pid = fork();
        if (pid == 0)
        {
            execvp(inputArray[0], inputArray);
            printf("Ivalid Input\n");
        }
        wait(NULL);

        printf("\nInterpreter: ");
        scanf(" %[^\n]s", iput); //takes the next itput to re-run
    }
    printf("\n.......");
    printf("\n..Bye..");
    printf("\n.......\n \n");
    return 0;
}