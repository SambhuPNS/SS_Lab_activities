/*8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.*/

#include<unistd.h>
#include<fcntl.h>
int main(){
	int  fd_src,count=0;
	char ch,buff[1024];
	fd_src = open("8source",O_RDONLY);
	while((read(fd_src,&ch,1))>0){
		if(ch!='\n') buff[count++]=ch;
		else{
			buff[count++] = '\n';
			write(1,buff,count);
			count=0;
		}
	}
	close(fd_src);
	return 0;
}
