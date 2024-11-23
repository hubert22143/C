/*
Zadanie 1/2
#include <stdio.h>
#include <stdlib.h>

void sumArr(int n,float arr[n]);
void reverseDigitsInArr(int n, float arr[n]);
void findMaxAndMin(int n, float arr[n]);
void count_elements(int n, float arr[n]);
int main()
{
    int n;
    printf("Ile liczb chcesz zapisac w tablicy? \n");
    scanf("%d",&n);
    float arr[n];
    for(int i = 0; i < n ; i++){
        printf("Zapisz swoj %d element w tablicy \n", i+1);
        scanf(" %f",&arr[i]);
    }
    int *p;
    for(int i = 0; i < n ; i++){
        p = &arr[i];
        printf("Adres elementu %d wynosi %p \n",i+1,p);
    }
    sumArr(n,arr);
    reverseDigitsInArr(n,arr);
    findMaxAndMin(n,arr);
    count_elements(n,arr);
    return 0;
}

void sumArr(int n,float arr[n]){
    int sum = 0;
    for(int i = 0; i < n ; i++){
    sum+=arr[i];
    }
    printf("Suma elementow w arrayu wynosi %d \n",sum);
}
void reverseDigitsInArr(int n, float arr[n]){
    float harmonicSumValue = 0;
    for(int i = 0 ; i < n ; i++){
    if(arr[i]!=0){}
        float reversed = 1.0 / arr[i];
        printf("Liczba ktora chcemy odwroric: %.2f jej odwrotna liczba %.2f \n",arr[i],reversed);
        arr[i] = reversed;
        harmonicSumValue += reversed;
        printf("Oraz sama ona, w tablicy po zamienieniu jej wartosci %f \n",arr[i]);
    }
    printf("Srednia Wartosc Harmoniczna wynosi : %f \n",n/harmonicSumValue);
    }
void findMaxAndMin(int n, float arr[n]){
    float min,max,temp;
    min = max = arr[0];
    for(int i = 0; i < n ; i++){
            printf("%f\n",arr[i]);
    if(max < arr[i]){
        max = arr[i];
    }else if(min > arr[i]){
    min = arr[i];
    }
    }
     // wartoscia maksymalna jest 1, poniewaz w reversedigitsinarr wartosc arrayu jest modyfikowana w reverseDigitsInArr, jest to celowy zabieg.
    printf("Wartosc maksymalna: %f  Wartosc minimalna: %f \n",max,min);
}
void count_elements(int n,float arr[n]){
int count_positive = 0,count_negative = 0,count_neutral = 0;
for(int i = 0; i < n ; i++){
    if(arr[i] < 0){
        count_negative++;
    }else if(arr[i] == 0){
    count_neutral++;
    }else if(arr[i]>0){
    count_positive++;
    }
}
printf("You have %d positive elements, %d negative elements and %d neutral elements in your array",count_positive,count_negative,count_neutral);
}
Zadanie 3.
#include <stdio.h>
void findDuplicates(int n,double arr[n]);
int main(void){
    int n = 10;
double arr[n];
printf("Podaj wartosci do 10-cio elemenowej tablicy: \n");
for(int i = 0; i < n; i++){
    int temp = 0;
    printf("Podaj %d liczbe do tablicy",i+1);
    scanf(" %d",&temp);
    arr[i] = temp;
}
findDuplicates(n,arr);
}
void findDuplicates(int n,double arr[n]){
    int duplicates = 0;
    for(int i = 0; i < n ; i++){
    int currentNumber = arr[i];
     for(int j = 0; j < n ; j++){
    if(i==j){
        continue;
    }
    if(currentNumber == arr[j]){
    duplicates++;
    }
    }
    }
    if(duplicates!=0){
        printf("Znaleziono duplikat liczby w arrayu \n");
    }else{
    printf("nie znaleziono duplikatu liczb");
    }
}

Zadanie 4
#include <stdio.h>
#define n 10

void main(void) {
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int lastArrElement = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = lastArrElement;

    for (int i = 0; i < n; i++) {
        printf("Shifted array by 1 to the right: %d \n", arr[i]);
    }
}
*/