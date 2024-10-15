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
int main(){
    int exampleArr[15] = {6,7,1,9,14,3,4,9,2,10,2,4,4,1,3};
    selectionSort(exampleArr,15);
    for(int i = 0; i<15 ; i++){
        printf("%d,",exampleArr[i]);
    }
}