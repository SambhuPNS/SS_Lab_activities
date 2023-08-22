//7.7.7.7.7.7.7.Write a program to copy file1 into file2 ($cp file1 file2).

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
   }

    char *source_path = argv[1];
    char *destination_path = argv[2];

    int source_fd = open(source_path, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file");
        return 1;
    }

    int dest_fd = open(destination_path, O_WRONLY);
    if (dest_fd == -1) {
        printf("Error opening destination file");
        close(source_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int  num_read;

    while ((num_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, num_read) != num_read; 
          
    }


    close(source_fd);
    close(dest_fd);

    printf("File copied successfully");

    return 0;
}

