 /*

============================================================================
Name : 22.c
Author : SAMBHU S S
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("forkfile", O_CREAT | O_RDWR , 0744);

	if(fork())
	{
		//parent process
		write(fd,"This is the parent process..\n",29);
	}
	else
	{
		//child process
		write(fd,"This is the child process..\n",29);
	}

	return 0;
}
