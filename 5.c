/*5. Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd.*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int num_files = 5;

    for (int i = 1; i <= num_files; i++) {
        char file_name[20];
        snprintf(file_name, sizeof(file_name), "file%d.txt", i);

        int file_descriptor = creat(file_name, S_IRUSR | S_IWUSR);

        if (file_descriptor == -1) {
            perror("Error creating file");
            return 1;
        }

        printf("File created successfully: %s (File Descriptor: %d)\n", file_name, file_descriptor);

     //   close(file_descriptor);
    }
    
    while (1) {
    //    printf("This is an infinite loop.\n");
    }
    return 0;
}

