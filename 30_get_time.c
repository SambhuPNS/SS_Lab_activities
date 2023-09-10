/*

Script for deamon process

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>

int main()
{
	int i=3; 

	int fd = open("time.txt",O_CREAT | O_RDWR | O_APPEND, 0774);

	while(i)
	{
		time_t t = time(NULL);	//get time in seconds
		struct tm *tm = localtime(&t); //breaks down time into year, month, day and so on
		char *t1 = asctime(tm); //converts the broken-down time value into a null-terminated string

		lseek(fd,0L,SEEK_END);

		int j=0;
		while(t1[j] != '\0')
		{
			write(fd,&t1[j],1);
			j++;
		}
		
		i--;
		sleep(60); 
	}

	return 0;
}
