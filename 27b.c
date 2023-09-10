/*

============================================================================
Name : 27b.c
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

	//execlp - only executable file need to be specified.The command itself will search for the path
        execlp("ls","ls","-Rl",NULL);

        return 0;
}
