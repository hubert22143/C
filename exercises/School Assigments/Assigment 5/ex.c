/*
ex 4
#include <stdio.h>
void switchMatrixPositions(int matrixSize,int threeDimensionalMatrix[matrixSize][matrixSize][matrixSize]);
void printThreeDimensionalMatrixValues(int matrixSize,int matrix[matrixSize][matrixSize][matrixSize]);
int main(void){
    int n;
    printf("Write a size of your 3D Matrix \n");
    scanf(" %d",&n);
    int matrix[n][n][n];
    printf("Write values to your 3D matrix \n");
    int valueHolder = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            for(int k = 0; k < n; k++){
                scanf(" %d",&valueHolder);
                matrix[i][j][k] = valueHolder;
            }
        }
    }
    printf("3D Matrix before change: \n");
    printThreeDimensionalMatrixValues(n,matrix);
    switchMatrixPositions(n,matrix);
    printf("After change(index+1(if matrix is  matrix[i][j][k] then i = k, j = i, k = j)) \n");
    printThreeDimensionalMatrixValues(n,matrix);
}
void switchMatrixPositions(int matrixSize,int threeDimensionalMatrix[matrixSize][matrixSize][matrixSize]){
    int holdModifiedMatrixPositions[matrixSize][matrixSize][matrixSize];
        for(int i = 0; i < matrixSize; i++){
            for(int j = 0; j < matrixSize; j++){
               for(int k = 0; k < matrixSize; k++){
                holdModifiedMatrixPositions[k][i][j] = threeDimensionalMatrix[i][j][k];
               }
             }
         }
        for(int i = 0; i < matrixSize; i++){
            for(int j = 0; j < matrixSize; j++){
               for(int k = 0; k < matrixSize; k++){
                threeDimensionalMatrix[i][j][k] = holdModifiedMatrixPositions[i][j][k];
               }
             }
        }
}
void printThreeDimensionalMatrixValues(int matrixSize,int matrix[matrixSize][matrixSize][matrixSize]){
        for(int i = 0; i < matrixSize; i++){
            printf("\nLayer: %d \n",i+1);
        for(int j = 0; j < matrixSize ; j++){
            printf(" Row %d: \n",j+1);
            for(int k = 0; k < matrixSize; k++){
                printf(" Column: %d Value: %4d \n",k+1,matrix[i][j][k]);
            }
        }
    }
}
*/
/*
ex 3
#include <stdio.h>
#define N 4
void switch_row_places_with_each_other(int arr[N][N]);
void printMatrix(int i, int j, int arr[i][j]);
int main(void){
    int arr[N][N] = {1,2,3,4,11,22,33,44,111,222,333,444,1111,2222,3333,4444};
    printf("Values of matrix before change: \n");
    printMatrix(N,N,arr);
    printf("Changing values... \n");
    switch_row_places_with_each_other(arr);
    printf("Values of matrix after change: \n");
    printMatrix(N,N,arr);
    return 0;
}
void switch_row_places_with_each_other(int arr[N][N]){
    int savedLastRow[N];
    for(int i=0;i<N;i++){
        savedLastRow[i] = arr[N - 1][i];
    }
    for(int i = N - 1; i >0 ; i--){
        if(i==0) break;
        for(int j = 0; j <4 ; j++){
            arr[i][j] = arr [i-1][j];
        }
    }
    for(int i = 0; i <N; i++){
        arr[0][i] = savedLastRow[i];
    }
}
void printMatrix(int i, int j, int arr[i][j]){
    for(int row = 0; row < i; row++){
        for(int column = 0; column < j; column++){
            printf("Row: %d Column %d value: %d \n",row + 1, column + 1,arr[row][column]);
        }
    }
}
*/
/*
ex 2
#include <stdio.h>
void assignValuesToGivenMatrix(int i, int j,int arr[i][j]);
void printMatrix(int i, int j, int arr[i][j]);
void sumDiagonalOfGivenMatrix(int i, int j, int arr[i][j]);
int main(void){
    int i,j;
    printf("How many rows do you want? : ");
    scanf("%d",&i);
    printf("How many collumns do you want? : ");
    scanf("%d",&j);
    int arr[i][j];
    printf("Assign values to your matrix: \n");
    assignValuesToGivenMatrix(i,j,arr);
    printMatrix(i,j,arr);
    sumDiagonalOfGivenMatrix(i,j,arr);
    printMatrix(i,j,arr);
    return 0;
}
void assignValuesToGivenMatrix(int i,int j,int arr[i][j]){
for(int row = 0; row < i; row++ ){
    for(int column = 0; column < j; column++){
        int temp = 0;
        //begin count with user-friendly usage
        printf("Write a value for row %d column %d: \n",row + 1, column + 1);
        scanf("%d",&temp);
        arr[row][column] = temp;
    }
}
}
void printMatrix(int i, int j, int arr[i][j]){
    for(int row = 0; row < i; row++){
        for(int column = 0; column < j; column++){
            printf("Row: %d Column %d value: %d \n",row + 1, column + 1,arr[row][column]);
        }
    }
}
void sumDiagonalOfGivenMatrix(int i, int j, int arr[i][j]){
int sum = 0;
for(int row = 0; row < i ; row++){
    for(int column = 0; column < j ; column ++){
        if(row == column){
            sum += arr[row][column];
            //assign 0 to values over diagonal value(example, a[2][2] = someValue, over it is a[1][2], assign it a value of 0)
            //additional parameter not linked to the general supposed usage of the function, used only in order to complete the exercise
            // skip for first row
            if(row == 0 && column == 0) continue;
                arr[row-1][j] = 0;
        }
    }
}
printf("Sum of diagonal is equal to: %d \n",sum);
}
*/
// ex. 1
// #include <stdio.h>
// #define N 10
// //int sum_two_arrays_and_return_in_third(int n,int arr[],int secondArr[],int thirdArr[]);
// //int compare_and_assign_higher(int n, int firstArr[],int secondArr[],int assignArr[]);
// int reassign_firstArr_values_to_secondArr(int assignFrom[],int assignTo[]);
// void printArrValues(int n,int arr[]);
// int main(void){
//     int firstArr[N] = {5,4,3,2,1,5,2};
//     int secondArr[N] = {1,4,3,1,2,9,15};
//     int thirdArr[N] = {0};
//     // VV declaring N is pointless since it's macro and it's global, but anyway I wanted to do it this way for while 
//     //sum_two_arrays_and_return_in_third(N,firstArr,secondArr,thirdArr);
//     //compare_and_assign_higher(N,firstArr,secondArr,thirdArr);
//     printf("First array: \n");
//     printArrValues(N,firstArr);
//     printf("Second array: \n");
//     printArrValues(N,secondArr);
//     reassign_firstArr_values_to_secondArr(firstArr,secondArr);
//     printf("Second array: after reassigning values \n");
//     printArrValues(N,secondArr);
//     printf("Third array: \n");
//     printArrValues(N,thirdArr);
//     reassign_firstArr_values_to_secondArr(secondArr,thirdArr);
//     printf("Third array: after reassigning values \n");
//     printArrValues(N,thirdArr);
//     printf("First array: \n");
//     //VV pointless(because it wont change anything), but doing as exercise says
//     reassign_firstArr_values_to_secondArr(thirdArr,firstArr);
//     printArrValues(N,firstArr);
//     //printArrValues(N,thirdArr);
//     return 0;
// }
// int reassign_firstArr_values_to_secondArr(int assignFrom[],int assignTo[]){
// for(int i = 0; i<N;i++){
//     assignTo[i] = assignFrom[i];
// }
// return 0;
// }
// /*
// int compare_and_assign_higher(int n, int firstArr[],int secondArr[],int assignArr[]){
// for(int i = 0; i < n ; i++){
//     if(firstArr[i] > secondArr[i]){
//         assignArr[i] = firstArr[i]; 
//     }else if(secondArr[i] > firstArr[i]){
//         assignArr[i] = secondArr[i];
//     }else{
//         //doesn't matter which one we sign in since it has same value
//         assignArr[i] = firstArr[i];
//     }
// }
//     return 0;
// }

// int sum_two_arrays_and_return_in_third(int n,int arr[],int secondArr[],int thirdArr[]){
// for(int i = 0; i < n ; i++){
//     thirdArr[i] = arr[i] + secondArr[i];    
// }
// return 0;
// }
// */
// void printArrValues(int n, int arr[]){
//     for(int i = 0; i < n ; i++){
//         printf("%d\n",arr[i]);
//     }
// }