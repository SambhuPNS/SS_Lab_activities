/*9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change*/


#include<sys/stat.h>
#include<stdio.h>


int main(void){
	char path[100] = "newfile";
	struct stat fstat;

	stat(path, &fstat);

	printf("%ld\n", fstat.st_ino);
	printf("%ld\n", fstat.st_nlink);
	printf("%ld\n", fstat.st_uid);
	printf("%ld\n", fstat.st_gid);
	printf("%ld\n", fstat.st_size);
	printf("%ld\n", fstat.st_blksize);
	printf("%ld\n", fstat.st_blocks);
	printf("%ld\n", fstat.st_atim);
	printf("%ld\n", fstat.st_mtim);
	printf("%ld\n", fstat.st_ctim);
}

//9.c
