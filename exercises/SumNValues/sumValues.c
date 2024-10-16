#include <stdlib.h>
#include <stdio.h>
void sumNValues(int n[], int index){
    n[index - 1] = 1e6;
    int sum = 0;
    for(int i = 0; i<index;i++){
        sum +=n[i];
    }
    printf("%d",sum);
}
int main(){
    int arr[] = {6,8,4,5,2,1,3,4,5,6,7,1,2};
    int index = sizeof(arr) / sizeof(arr[0]); 
    sumNValues(arr,index);
}