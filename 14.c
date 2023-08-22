//14 Write a program to find the type of a file.
//a. Input should be taken from command line.
//b. program should be able to identify any type of a file.

#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>
#include<time.h>
#include<stdio.h>
#include<sys/sysmacros.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	struct stat sb;

	if(argc!=2){
		printf("total number of agrument is %d instead of 2",argc);
		exit(EXIT_FAILURE);
	}

	if(lstat(argv[1], &sb) == -1){
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	printf("File type:                      ");

	switch( sb.st_mode & S_IFMT) {
		case S_IFBLK: printf("block device\n"); 
			      break;
		case S_IFCHR: printf("character device\n");
			      break;
		case S_IFDIR: printf("directory\n");
			      break;
		case S_IFIFO: printf("FIFO/pipe\n");
			      break;
		case S_IFLNK: printf("symlink\n");
			      break;
		case S_IFREG: printf("regular file\n");
			      break;
		case S_IFSOCK: printf("socket\n");
			       break;
		default: printf("unknown?\n");
			      break;
	}
}
