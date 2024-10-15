#include <stdio.h>
#include <stdlib.h>
void divisors(int number){
    int *divisor;
    divisor= (int *)malloc(number * sizeof(int));
    if(divisor==NULL){
        printf("Allocation memmory has failed");
    }
    printf("Your divisor numbers are : %d",*divisor);
    for(int i = 0; i<number ; i++){
        if(number%i==0){
            divisor[i]+=i;
            printf("%d",i);
        }
    }
}
int main(){
    int number = 15;
    divisors(number);
}