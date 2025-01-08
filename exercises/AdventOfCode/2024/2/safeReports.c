#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readFile();
void printArray(int size, int arr[]);
void isSafeArray(int size, int arr[],int currentElement);
int main(void)
{
    readFile();

    return 0;
}

void readFile()
{
    char *filename = "beginningArray.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    char line[256];
    while (fgets(line, 256, fp))
    {
        size_t lineLength = strlen(line);
        size_t currentIndex = 0;
        int *currentLine = malloc(lineLength * sizeof(int));
        for(int i = 0; i < lineLength ; i++){
            while(line[i] >= '0' && line[i] <= '9'){
                int num = 0;
                currentLine[currentIndex] = line[i] - '0';
                if(line[i + 1] >='0' && line[i+1] <= '9'){
                    currentLine[currentIndex] = (currentLine[currentIndex] * 10) + line[i+1];
                    i++;
                    i++;
                    currentIndex++;
                    continue;
                
                }
                currentIndex++;
                i++;
            }
        }

        printArray(currentIndex, currentLine);  
        printf("\n");
    }
}
void printArray(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}
void isSafeArray(int size, int arr[], int currentElement){
    int isSafe = 0;
    int currentIndex = 0;
    int isAscending = 0;
    int isDescending = 0;
    if(currentIndex>=size){
        return 0;
    }
    if(arr[currentIndex] < arr[currentIndex+1] && isDescending == 0){
        isAscending = 1;
        currentIndex++;
        return isSafeArray(size,arr[],)
    }else if(arr[currentIndex] > arr[currentIndex+1] && isAscending == 0){
        isDescending == 1;
        currentIndex++;
    }
}