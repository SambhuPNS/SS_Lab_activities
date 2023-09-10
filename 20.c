/*

============================================================================
Name : 20.c
Author : SAMBHU S S
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<sys/resource.h>	//getpriority, setpriority
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int priority = getpriority(PRIO_PROCESS,0); //0 indicates current process
	
	if(priority == -1)
	{
		perror("Unable to get process priority : ");
	      	exit(0);	
	}

	printf("Current process priority : %d\n",priority);
	
	int errno = 0; //to detect error 
	//modify priority using nice command
	int ret = nice(-4);
	printf("return value of nice : %d\n",ret);

	if(errno)
		perror("Status of nice sys call : ");

	printf("Modified process priority : %d\n",getpriority(PRIO_PROCESS,0));

	return 0;
}

