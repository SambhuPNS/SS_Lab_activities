#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *file_path = "test_file.txt";

    int file_descriptor = creat(file_path, S_IRUSR | S_IWUSR);

    if (file_descriptor == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully with file descriptor: %d\n", file_descriptor);

    close(file_descriptor);

    return 0;
}

