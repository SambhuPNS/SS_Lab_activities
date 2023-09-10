/*

============================================================================
Name : 17a.c
Author : Sambhu S S
Description : Write a program to simulate online ticket reservation. 
	a.Write a program to open a file, store a ticket number and exit.
Date: 25th Aug, 2023.
============================================================================

*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int fd,i=0;

	struct	
	{
		int ticket_no;
	}db;

	db.ticket_no = i+1;	//ticket no.

	fd=open("record.txt",O_RDWR);
	write(fd,&db,sizeof(db));	//store ticket no. in file

	close(fd);

	return 0;
}
