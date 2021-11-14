#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Open inputfile with read and output file with write access
    FILE *inputFile = fopen("grades.txt", "r");
    FILE *outputFile = fopen("average.txt", "w");
    //checks for error and terminates if there is any
    if (inputFile == NULL)
    {
        printf("File could not be found.\n");
        return 1;
    }
    if (outputFile == NULL)
        printf("Error: Output file could not be found to write in!\n");

    int chapters = 2, homeWorks = 2, students = 10;
    int columns = chapters * homeWorks;
    int grades[students][columns];

    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < columns; j++)
        { // transfer data from file to array and print on console
            fscanf(inputFile, "%d", &grades[i][j]);
            printf("%d ", grades[i][j]);
            if ((j + 1) % (columns) == 0)
                printf("\n");
        }
    }
    fclose(inputFile);

    int n = chapters; //managers
    for (int i = 0; i < chapters; i++)
    {
        int manager = fork();
        if (manager < 0)
        {
            perror("fork");
            return 1;
        }
        else if (manager == 0)
        {
            int h = homeWorks; // workers per manager
            for (int j = 0; j < homeWorks; j++)
            {

                int worker = fork();
                if (worker < 0)
                {
                    perror("fork");
                    return 1;
                }
                else if (worker == 0)
                { // worker processes
                    double sum = 0;
                    for (int s = 0; s < students; s++)
                        sum += grades[s][(i * chapters) + j];
                    double avg = sum / students;
                    printf("Chapter: %d ->> HW: %d, Average = %g\n", i + 1, j + 1, sum / students);

                    if (outputFile != NULL)
                    {
                        fprintf(outputFile, "Chapter: %d ->> HW: %d, Average = %g\n", i + 1, j + 1, sum / students); // store in output file
                    }

                    exit(0);
                }
            }

            while (h > 0)
            { // managers wait for the workers
                wait(NULL);
                h--;
            }
            exit(0);
        }
        printf("\n");
    }
    while (n > 0)
    { // parent waiting for the managers
        wait(NULL);
        n--;
    }

    fclose(outputFile);
    return 0;
}