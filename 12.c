//12. Write a program to find out the opening mode of a file. Use fcntl.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){

	int fd = open("fcntlfile.txt", O_RDWR | O_CREAT);
	printf("\npresent file descripter %d\n", fd);
	
	int mode = fcntl(fd, F_GETFL);
	printf("\nfile mode is %d\n", mode);

	return 0;
}
// 12.c 
