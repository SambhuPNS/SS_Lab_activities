/*

============================================================================
Name : 16b.c
Author : Sambhu S S
Description : Write a program to perform mandatory locking.
                b. Implement read lock
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

        lock.l_type=F_RDLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=0;
        lock.l_len=0;
        lock.l_pid=getpid();

        printf("Before entering the critical section\n ");
        fcntl(fd,F_SETLKW,&lock);       //locking

        printf("Inside the critical section \n");
        printf("Enter to unlock\n");
        getchar();
	
	lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK,&lock);        //unlocking

        printf("Unlocked\n");

        printf("Finish\n");

        close(fd);
}

