/*

============================================================================
Name : 17b.c
Author : Sambhu S S
Description : Write a program to simulate online ticket reservation. 
	b.Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 25th Aug, 2023.
============================================================================

*/

#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	struct{
		int ticket_no;
	}db;

	struct flock lock;

	int fd;
	fd = open("record.txt",O_RDWR);
	read(fd,&db,sizeof(db));

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	printf("Before entering the critical section\n");
	fcntl(fd,F_SETLKW,&lock);	//locking-writelock
	
	printf("Inside the critical section\n");

	printf("Current ticket no.: %d\n",db.ticket_no);
	db.ticket_no++;	//increment ticket no.
		
	lseek(fd,0L,SEEK_SET);	//update ptr to start of file

	write(fd,&db,sizeof(db));	//updating db

	printf("Enter to unlock\n");
	getchar();
	
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);	//unlocking
	printf("Unlocked\n");
	
	printf("Finish\n");
	close(fd);

	return 0;
}

