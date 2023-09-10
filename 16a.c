/*

============================================================================
Name : 16a.c
Author : Sambhu S S
Description : Write a program to perform mandatory locking.
		a. Implement write lock
Date: 25th Aug, 2023.
============================================================================

*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	printf("Before entering the critical section\n ");
	fcntl(fd,F_SETLKW,&lock);	//locking
	
	printf("Inside the critical section \n");
	printf("Enter to unlock\n");
	getchar();

	printf("Unlocked\n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);	//unlocking
	
	printf("Finish\n");

	close(fd);

	return 0;
}

