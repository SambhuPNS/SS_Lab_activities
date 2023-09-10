/*

============================================================================
Name : 27e.c
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

	const char* ls_envp[]={"PATH=/bin/:/usr/bin",0,0};

        execvp("ls",(void *)ls_envp);

        return 0;
}
