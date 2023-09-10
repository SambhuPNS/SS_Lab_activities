/*

============================================================================
Name : 18_createrecord.c
Author : Sambhu S S
Description : Write a program to perform Record locking.
	a. Implement write lock
	b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
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
	int i,fd;

	struct{
		int train_no;
		int ticket_cnt;
	}db[3];
	
	for(i=0;i<3;i++)
	{
		db[i].train_no = i+1;
		db[i].ticket_cnt = 0;
	}

	fd = open("record1.txt",O_RDWR);
	write(fd,db,sizeof(db));

	close(fd);

	return 0;
}
