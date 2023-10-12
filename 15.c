/*

============================================================================
Name : 15.c
Author : Sambhu S S
Description : Write a program to display the environmental variable of the user (use environ).
Date: 25th Aug, 2023.
============================================================================

*/


#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(void){
int i=0;

while(environ[i]){
	printf("%s\n", environ[i++]);
}
}
