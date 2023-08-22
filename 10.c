/*10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("seekfile.txt", O_RDWR | O_CREAT);
	printf("fd = %d\n", fd);

	char buf = 's';

	for(int i=0; i<10; i++){
		write(fd, &buf,1);
	}
	int l = lseek(fd, 10, SEEK_CUR);

	buf = 'x';
	for(int i =0; i<10; i++){
		write(fd,&buf, 1);
	}

	printf("lseek value %d",l);

	return 0;
}

// 10.c
// od -c seekfile.txt
//  Can be used to  
