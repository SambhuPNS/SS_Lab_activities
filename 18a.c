/*

============================================================================
Name : 18a.c
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

struct{
	int train_no;
	int ticket_cnt;
}db;

int main()
{
	int fd,num;
	fd=open("record1.txt",O_RDWR);
	
	printf("Select train no.(1,2,3): ");
	scanf("%d",&num);

	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(num-1)*sizeof(db);//start of record
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();

	printf("Before entering into critical section\n");
        fcntl(fd,F_SETLKW,&lock);       //locking

	printf("Inside critical section\n");

	//reading ticket no.
	lseek(fd, (num-1)*sizeof(db), SEEK_SET); //reading only a particular record
	read(fd,&db,sizeof(db));

	printf("Ticket no.: %d\n",db.ticket_cnt);
	db.ticket_cnt++;	//increment ticket count
	lseek(fd, -1*sizeof(db), SEEK_CUR);	//move ptr to start of current record
	write(fd, &db ,sizeof(db));	//updating record with new ticket no.
	
	printf("To book ticket presss Enter \n");
	getchar();
	getchar();

	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock); //unlocking
	
	printf("Booked\n");
	close(fd);

	return 0;
}
