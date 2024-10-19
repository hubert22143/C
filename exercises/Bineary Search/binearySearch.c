#include <stdio.h>

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex!= i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
void binearySearch(int searchedNumber, int arr[], int size){
    int foundAtLeastOnce = 0;
    int low = 0;
    int high = size - 1;
    while(low<=high){
      int mid = (low + high) / 2;
      if(arr[mid] == searchedNumber){
        foundAtLeastOnce = 1;
        printf("Searched number %d has been found at index %d \n",searchedNumber,mid);
           int leftIndex = mid - 1;
            while (leftIndex >= low && arr[leftIndex] == searchedNumber) {
                printf("Searched number %d has also been found at index: %d\n", searchedNumber, leftIndex);
                leftIndex--;
            }
            int rightIndex = mid + 1;
            while (rightIndex <= high && arr[rightIndex] == searchedNumber) {
                printf("Searched number %d has also been found at index: %d\n", searchedNumber, rightIndex);
                rightIndex++;
            }
            break;
      }else if(arr[mid]<searchedNumber){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    if (!foundAtLeastOnce){
      printf("Searched number %d does not exist in the array",searchedNumber);
    }
}
int main(){
    int arr[] = {5,4,3,3,3,3,3,2,5,5,5,1,3,2,4,8,4,5,24,24,41,5,78,142,5353,4145,262,724,958,1423,4515,2341,3452,1234,5662,1311,42,13,24,61,413};
    int arrLen = sizeof(arr) / sizeof(int);
    int searchedNumber = 3525;
    selectionSort(arr,arrLen);
    binearySearch(searchedNumber,arr,arrLen);

}