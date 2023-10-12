#include<unistd.h>
#include<stdio.h>

int main()
{
	long PIPE_BUF, OPEN_MAX;

	PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
	OPEN_MAX = sysconf(_SC_OPEN_MAX);

	printf("Size of a pipe (circular buffer) = %ld",PIPE_BUF);
	printf("\nMax number of files = %ld",OPEN_MAX);

	return 0;
}
