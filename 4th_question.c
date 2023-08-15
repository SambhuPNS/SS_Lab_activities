#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char *file_path = "test_file.txt";

    int file_descriptor = open(file_path, O_RDWR | O_EXCL);

    if (file_descriptor == -1) {
        if (errno == EEXIST) {
            printf("File is already open or exists.\n");
        } else {
            perror("Error opening file");
            return 1;
        }
    } else {
        printf("File opened successfully with file descriptor: %d\n", file_descriptor);

        close(file_descriptor);
    }

    return 0;
}

