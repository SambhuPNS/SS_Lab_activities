/*

============================================================================
Name : 24.c
Author : SAMBHU S S
Description : Write a program to create an orphan process.
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	if(!fork())
	{
		//child process
		printf("Child pid : %d\n",getpid());
		printf("Before Orphan - child ppid : %d\n",getppid());

		sleep(3);
		
		//orphan process ppid should be 1 or should start with 1
		printf("After Orphan - child ppid : %d\n",getppid());
	}
	else
	{
		//parent process
		sleep(1);
		printf("Parent pid : %d\n",getpid());
	}
	
	return 0;
}
