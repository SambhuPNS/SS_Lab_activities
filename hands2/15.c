#include<stdio.h>
#include<unistd.h>


int main()
{
	char buf[50];
	int fd[2];

	pipe(fd); //always create pipe before fork()
	
	if(fork()) //parent
	{
		close(fd[0]); //closing the read end of pipe
		
		printf("Enter msg to child : ");
		scanf("%[^\n]",buf);

		write(fd[1], buf, sizeof(buf));
	}
	else //child
	{
		close(fd[1]); //close write end of pipe

		read(fd[0], buf, sizeof(buf));

		printf("Msg from parent : %s\n", buf);
	}

	return 0;
}
