#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];	//create file descriptors : fd[0]-read fd[1]-write
	char buf[20];

	pipe(fd);	//create pipe

	//write to the pipe
	write(fd[1], "Hi Sambhu!", 10);

	//read from the pipe
	read(fd[0], buf, sizeof(buf));

	//display msg read from pipe
	printf("Read from pipe : %s\n", buf);

	return 0;
}
