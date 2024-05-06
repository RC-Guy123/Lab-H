#include <stdlib.h>
#include <stdio.h>
int main(void) {
    // Get user input
    #define N 256
    char buffer[N+1], *filename = buffer;
    char ch;
    int i = 0; // counter for how many characters read
    printf("Enter a file name: ");
    while ((ch = getchar()) != '\n') { // get one character at a time
        filename[i++] = ch;
    // Enter your code under here
        if (i >= N) {
            printf("Error!\n");
            return EXIT_FAILURE;
        }
    }
    for (; i < N+1; i++) { // fill the rest of the array with null characters
        filename[i] = '\0';
    }
    // Enter your code under here
    int dot_position = -1;
    for (int j = i - 1; j >= 0; j--) {
        if (filename[j] == '.') {
            dot_position = j;
            break;
        }
    }
    if (dot_position == -1 || dot_position == 0 || dot_position == i - 1) {
        printf("Error!\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", &filename[dot_position]);
    return EXIT_SUCCESS;
}