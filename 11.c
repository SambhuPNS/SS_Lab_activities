/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("dupfile.txt", O_RDWR | (O_CREAT | O_APPEND));
	//int fd = open("dupfile.txt", "a");
	printf("\npresent fd is %d\n", fd);	
	int newdup = dup(fd);
	printf("\nnew duplicated fd with dup %d\n", newdup);
	char fd1[10];
	char fd2[10];
	sprintf(fd1,"%d", fd);
	sprintf(fd2,"%d %d\n", fd, newdup);
	printf("fd %s\n", fd1);
	printf("newdup %s\n", fd2);
	write(newdup, fd2, 10);
	//write(newdup, &fd, sizeof(int));
	//write(newdup, &newdup, sizeof(int));
	/*
	int newdup2 = dup2(fd, 5);
	printf("\nnew duplicated fd with dup2 %d\n", newdup2);

	int newfcntl = fcntl(fd, F_DUPFD);
	printf("\nnew duplicated fd with fcntl %d\n", newfcntl);
	*/
} //11.c 


//dup function is used to duplicate a file descriptor. It creates a new file descriptor that refers to the same open file description as the original file descriptor. This can be particularly useful in cases where you want multiple file descriptors to refer to the same file, such as when working with multiple standard streams or when redirecting input and output.

//integer to string conversion is done using sprinttf function

//
