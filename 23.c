/*

============================================================================
Name : 23.c
Author : SAMBHU S S
Description : Write a program to create a Zombie state of the running program.
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork())
	{
		sleep(10);
		printf("Parent exits..\n");
	}
	else
	{
		printf("Child in zombie state..\n");
	}

	return 0;
}

