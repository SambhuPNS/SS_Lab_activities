//15)Write a program to display the environmental variable of the user (use environ)


#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(void){
int i=0;

while(environ[i]){
	printf("%s\n", environ[i++]);
}
}
