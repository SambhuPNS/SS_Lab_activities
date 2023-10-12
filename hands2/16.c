#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd1[2],fd2[2];
	char buf1[50],buf2[50];;

	pipe(fd1);
	pipe(fd2);

	if(!fork()) //child
	{
		close(fd1[0]); //close read end of pipe 1

		printf("Enter msg to parent : ");
		scanf("%[^\n]",buf1);
		write(fd1[1], buf1, sizeof(buf1));

		close(fd2[1]); //close write end of pipe 2

		read(fd2[0], buf2, sizeof(buf2));
		printf("Msg from parent : %s\n",buf2);
	}
	else
	{
		close(fd1[1]); //close write end of pipe 1
		
		read(fd1[0], buf1, sizeof(buf1));
		printf("Msg from child : %s\n",buf1);

		close(fd2[0]); //close read end of pipe 2

		printf("Enter msg to child : ");
		scanf("%[^\n]",buf2);
		write(fd2[1], buf2, sizeof(buf2));
	}

	return 0;
}

