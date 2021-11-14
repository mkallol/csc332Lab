/*
Moshahid Kallol
csc 332 H
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])

{
    char *filepath = argv[1];
    int returnval;

    //Checking for existance
    returnval = access(filepath, F_OK);
    if (returnval == 0)
    {
        printf("\n '%s' file exists. \n", filepath);
    }
    else
    {
        if (errno == ENOENT) //checking if file exist.
        {
            printf("%s does not exist\n", filepath);
        }
        else if (errno == EACCES) //checkig if file is accessible.
            printf("%s is not accessible\n", filepath);
        return 0;
    }
    // Check read access
    returnval = access(filepath, R_OK);
    if (returnval == 0)
    {
        printf("\n '%s' file has READ permission \n", filepath);
    }
    else
    {
        if (errno == ENOENT) //checking if file exist.
        {
            printf("'%s' does not exist\n", filepath);
        }
        else if (errno == EACCES) //checkig if file is accessible.
            printf("'%s' is not accessible\n", filepath);
        return 0;
    }

    // Check write access
    returnval = access(filepath, W_OK);
    if (returnval == 0)
    {
        printf("\n '%s' file has WRITE permission \n \n", filepath);
    }
    else
    {
        if (errno == ENOENT) //checking if file exist.
        {
            printf("'%s' does not exist\n", filepath);
        }
        else if (errno == EACCES) //checkig if file is accessible.
            printf("'%s' is not accessible\n", filepath);
        return 0;
    }

    return 0;
}