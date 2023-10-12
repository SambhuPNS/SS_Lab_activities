#include <stdio.h>
#include <unistd.h>

int main() {
    const char* target = "file_for_learning_links.txt";
    const char* link_name = "soft_link2.txt";

    if (symlink(target, link_name) == -1) {
        perror("Error creating soft link");
        return 1;
    }

    printf("Soft link created successfully!\n");

    return 0;
}

