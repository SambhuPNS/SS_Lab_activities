#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	//c
	int fd;
	fd = mknod("myfifo1", S_IFIFO | 0744, 0);
	printf("fd = %d\n",fd);
	if(fd == 0)
		printf("FIFO created using mknod()...\n");

	//d
	int fd1;
        fd1 = mkfifo("myfifo",0744);
        printf("fd = %d\n",fd1);
	if(fd1 == 0)
		printf("FIFO created using mkfifo()..\n");

	return 0;
}
