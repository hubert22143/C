#include <stdio.h>
#include <stdlib.h>

void linearSearch(int arr[], int searchedNumber, int arrLength) {
    int *indexHolder = malloc(arrLength * sizeof(int));
    int matches = 0;

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] == searchedNumber) {
            indexHolder[matches] = i;
            matches++; 
        }
    }

    if (matches > 0) {
        printf("Your number is matched on indexes: ");
        for (int i = 0; i < matches; i++) {
            printf("%d ", indexHolder[i]);
        }
        printf("\n");
    } else {
        printf("Matched index has not been found\n");
    }

    free(indexHolder); 
}

int main() {
    int testArr[] = {4, 1, 2, 3, 4, 777, 1, 2, 3, 4, 51, 51, 5, 25, 25, 2, 53, 53, 53, 41, 4123, 1, 416, 71, 765, 867, 98, 958, 67};
    int arrLength = sizeof(testArr) / sizeof(testArr[0]);
    int search = 3;
    linearSearch(testArr, search, arrLength);

    return 0;  // Return success from main
}