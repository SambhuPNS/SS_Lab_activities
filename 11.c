
/*
============================================================================
Name : 11.c
Author : Sambhu S S
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
Date: 25th Aug, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4;
	fd1 = open("dupfile", O_RDWR | O_CREAT | O_APPEND);
	fd2 = dup(fd1);
	
	printf("fd1 = %d\nfd2 = %d\n", fd1,fd2);

	char filed1[10];
	char filed2[10];
	sprintf(filed1,"%d",fd1);
	sprintf(filed2,"%d",fd2);
	
	write(fd1,&filed1,10);
	write(fd2,&filed2,10);

	dup2(fd2,fd3);
	fd4 = fcntl(fd1,F_DUPFD);	//same as fd2=dup(fd1)

       	printf("fd4 = %d\n",fd4);
	char filed4[10];
	sprintf(filed4,"%d",fd4);
	write(fd4,&filed4,10);	

	close(fd1);

	close(fd3);
	close(fd4);
}

