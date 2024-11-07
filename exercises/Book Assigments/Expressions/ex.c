#include <stdio.h>

int main(void) {
    const int segments[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},  // Representation for '0'
        {0, 1, 1, 0, 0, 0, 0},  // Representation for '1'
        {1, 1, 0, 1, 1, 0, 1},  // Representation for '2'
        {1, 1, 1, 1, 0, 0, 1},  // Representation for '3'
        {0, 1, 1, 1, 0, 1, 0},  // Representation for '4'
        {1, 0, 1, 1, 0, 1, 1},  // Representation for '5'
        {1, 0, 1, 1, 1, 1, 1},  // Representation for '6'
        {1, 1, 1, 0, 0, 0, 0},  // Representation for '7'
        {1, 1, 1, 1, 1, 1, 1},  // Representation for '8'
        {1, 1, 1, 1, 0, 1, 1}   // Representation for '9'
    };

    // Print top row for each digit
    for (int digit = 0; digit < 10; digit++) {
        printf(" %c ", segments[digit][0] ? '_' : ' ');  // Top horizontal segment
        printf("   ");
    }
    printf("\n");

    // Print middle row for each digit
    for (int digit = 0; digit < 10; digit++) {
        printf("%c", segments[digit][5] ? '|' : ' ');    // Top left vertical segment
        printf("%c", segments[digit][6] ? '_' : ' ');    // Middle horizontal segment
        printf("%c", segments[digit][1] ? '|' : ' ');    // Top right vertical segment
        printf("   ");
    }
    printf("\n");

    // Print bottom row for each digit
    for (int digit = 0; digit < 10; digit++) {
        printf("%c", segments[digit][4] ? '|' : ' ');    // Bottom left vertical segment
        printf("%c", segments[digit][3] ? '_' : ' ');    // Bottom horizontal segment
        printf("%c", segments[digit][2] ? '|' : ' ');    // Bottom right vertical segment
        printf("   ");
    }
    printf("\n");

    return 0;
}