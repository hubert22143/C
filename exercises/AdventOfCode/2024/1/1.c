#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void sortList(int[], int size);
void printList(int[], int size);
// int countDistance(int[], int[], int size);
void readFile(int[], int[]);
void similiarityScore(int[], int[], int);
// int *extractDigits(int);
int main(void)
{
    int *firstDynamicArray;
    int *secondDynamicArray;
    int arraySize = 1000;
    firstDynamicArray = malloc(arraySize * sizeof(int));
    secondDynamicArray = malloc(arraySize * sizeof(int));
    readFile(firstDynamicArray, secondDynamicArray);

    // sortList(firstDynamicArray,arraySize);
    // sortList(secondDynamicArray,arraySize);

    // int totalDistance = countDistance(firstDynamicArray,secondDynamicArray,arraySize);
    // printf("Total distance between two arrays is equal to: %d",totalDistance);

    similiarityScore(firstDynamicArray, secondDynamicArray, arraySize);
    return 0;
}
// void sortList(int arrToSort[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size - 1; j++)
//         {
//             if (arrToSort[j] > arrToSort[j + 1])
//             {
//                 int temp = arrToSort[j];
//                 arrToSort[j] = arrToSort[j + 1];
//                 arrToSort[j + 1] = temp;
//             }
//         }
//     }
// }
void printList(int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Arr[%d] : %d\n", i, list[i]);
    }
}
// int countDistance(int firstList[], int secondList[], int size)
// {
//     int totalDistance = 0;
//     int fluidValue = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (firstList[i] <= secondList[i])
//         {
//             fluidValue = secondList[i] - firstList[i];
//             totalDistance += fluidValue;
//         }
//         else
//         {
//             fluidValue = firstList[i] - secondList[i];
//             totalDistance += fluidValue;
//         }
//     }
//     return totalDistance;
// }
void readFile(int firstArray[], int secondArray[])
{
    char *filename = "distance.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s", filename);
        exit(1);
    }

    char line[256]; // Buffer to hold each line from the file
    int firstCurrentIndex = 0;
    int secondCurrentIndex = 0;

    while (fgets(line, 256, fp))
    {
        int num1, num2;
        // Use sscanf to extract two integers from the line
        if (sscanf(line, "%d  %d", &num1, &num2) == 2)
        {
            firstArray[firstCurrentIndex++] = num1;
            secondArray[secondCurrentIndex++] = num2;
        }
        else
        {
            printf("Error: Failed to parse line: %s\n", line);
        }
    }
    fclose(fp);
}
void similiarityScore(int firstArray[], int secondArray[], int size)
{
    long similiarityScore = 0;
    for (int i = 0; i < size ; i++)
    {
        int firstNumber = firstArray[i];
        int foundMatches = 0;
        for(int j = 0; j < size ; j++){
            int secondNumber = secondArray[j];
            if (firstNumber==secondNumber)
            {
                foundMatches++;
            }
        }
        similiarityScore += (firstNumber * foundMatches);
    }
    printf("Similiarity score is equal to %ld", similiarityScore);
}
//useless
// int *extractDigits(int number)
// {
//     int *digits = malloc(5 * sizeof(int));
//     int numDigits = 4;
//     while (number > 0)
//     {
//         digits[numDigits] = number % 10;
//         number = number / 10;
//         numDigits--;
//     }
//     return digits;
// }