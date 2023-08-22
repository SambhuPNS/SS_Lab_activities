//6.Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int  num_read;

    while ((num_read = read(0, buffer, BUFFER_SIZE)) > 0) {
        write(1, buffer, num_read);
      }
    return 0;
}

