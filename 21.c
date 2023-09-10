/*

============================================================================
Name : 21.c
Author :Sambhu S S
Description : Write a program, call fork and print the parent and child process id.
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork())
		printf("Parent  process id : %d\n",getpid());
	else
		printf("Child process id : %d\n",getpid());

	return 0;
}

