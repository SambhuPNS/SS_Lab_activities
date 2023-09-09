/*

============================================================================
Name : 13.c
Author :Sambhu S S
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 25th Aug, 2023.
============================================================================

*/

#include<sys/select.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(void){

	fd_set rfds;
	struct timeval tv;
	int retval;

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);

	if(retval == -1)
		perror("select()");
	else if (retval)
		printf("Data is available within 10 seconds\n");
	else
		printf("Data is NOT available within 10 seconds\n");

	return 0;
}

