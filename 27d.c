/*

============================================================================
Name : 27d.c
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
	
	const char *ls_argv[]={"ls","-Rl",0};
        execv("/bin/ls",(void *)ls_argv);

        return 0;
}
