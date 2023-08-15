#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char* fifo_name = "my_fifo";

    
    if (mknod(fifo_name, S_IFIFO,0) == -1) {
        perror("Error creating FIFO");
        return 1;
    }

    printf(" created successfully!\n");

    return 0;
}

