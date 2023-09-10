/*

============================================================================
Name : 27a.c
Author : SAMBHU S S
Description : Write a program to execute ls -Rl by the following system calls
                a. execl
                b. execlp
                c. execle
                d. execv
                e. execvp
Date: 1st Sep, 2023.
============================================================================

*/

#include<unistd.h>
#include<stdio.h>

int main()
{
        printf("Before execl..\n");

        //execl - full path need to be specified
        execl("/bin/ls","ls","-Rl",NULL);

        return 0;
}
