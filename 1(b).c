#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char* source_file = "file_for_learning_links.txt";
    const char* hardlink_name = "hardlink.txt";

    if (link(source_file, hardlink_name) == -1) {
        perror("Error creating hard link");
        return 1;
    }

    printf("Hard link created successfully!\n");

    return 0;
}

