/*

============================================================================
Name : 25.c
Author : Sambhu S S
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 1st Sep, 2023.
============================================================================

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int pid1,status;
	printf("Before calling fork...\n");
	pid1=fork();

	if(pid1==0) //child 1
	{
		printf("Chlid 1 pid : %d\n", getpid());
		printf("Chlid 1 ppid is : %d\n", getppid());
	}

	else
	{

		int pid2;
		//printf("inside first in parent\n");

		pid2=fork();

		if(pid2==0) //child 2
		{
			printf("Chlid 2 pid :  %d\n", getpid());
			printf("Chlid 2 ppid : %d\n", getppid());
		}
		else
		{
			int pid3;
			//printf("inside second in parent\n");
			pid3=fork();
			if(pid3==0) //child 3
			{
		       		sleep(10);
				printf("Chlid 3 pid : %d\n", getpid());
				printf("Child 3 ppid : %d\n", getppid());
				//printf("my thirdchlid is completed\n");
			}
			else
			{
				//waiting for child 3 to complete
	       			waitpid(pid3,&status, 0);
				printf("Child 3 exited with status : %d\n",status);
				printf("Parent pid :  %d\n", getpid());
			}
		}

	}
	return 0;
}
