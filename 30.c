/*

============================================================================
Name : 30.c
Author : SAMBHU S S
Description : Write a program to run a script at a specific time using a Daemon process. 
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int pid = fork();

	if(!pid)
	{
		//make childprocess session leader
		setsid();

		//deamon process will execute get_time pgm in the bg
		execl("/home/vboxuser/SSLab/30_get_time.c","30_get_time",NULL);
	}
	else
	{
		//killing parent process
		printf("Parent process exiting..\n");
		exit(0);
	}
	return 0;
}

