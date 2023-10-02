#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if at least one argument (program name) is provided
    if (argc >= 1) {
        // Print the program name (including path) followed by a new line
        printf("%s\n", argv[0]);
    } else {
        // Handle the case when no arguments are provided (unlikely in most scenarios)
        printf("No program name provided.\n");
    }
    return 0;
}
