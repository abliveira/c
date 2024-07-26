#include <stdio.h>

int main() {
    FILE *file;
    int num;

    // Attempt to open a file for reading
    file = fopen("example.txt", "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        goto error;  // Jump to the error handling section
    }

    // Attempt to read an integer from the file
    if (fscanf(file, "%d", &num) != 1) {
        printf("Error: Could not read integer from file.\n");
        goto close_file;  // Jump to the file closing section
    }

    // Print the read integer
    printf("The number read from the file is: %d\n", num);

    // Note: goto can make the control flow harder to follow and maintain
    // Generally recommended to use loops/functions instead of goto
    // This example is for demonstration purposes; goto must be avoid unless necessary

    // Close the file and end the program
    close_file:
    fclose(file);
    printf("File closed");
    return 0;

    // Error handling section
    error:
    printf("Error");
    return 1;

}
