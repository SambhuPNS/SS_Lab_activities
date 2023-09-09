/*

============================================================================
Name : 12.c
Author : Sambhu S S
Description : Write a program to find out the opening mode of a file. Use fcntl
Date: 25th Aug, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){

	int fd = open("fcntlfile.txt", O_RDWR | O_CREAT);
	printf("\npresent file descripter %d\n", fd);
	
	int mode = fcntl(fd, F_GETFL);
	printf("\nfile mode is %d\n", mode);

	return 0;
}
// 12.c 
