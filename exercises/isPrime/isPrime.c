#include <stdio.h>
#include <stdlib.h>
void isPrime(int number){
    if(number<2){
        printf("Number less than 2 is not a prime number.\n");
        return;
    }
    printf("Checking if number %d is prime\n",number);
        int is_prime = 1;
        for(int j = 2; j*j <=number; j++){
            if(number%j==0){
            is_prime = 0;
            break;
            };
        }
        if(is_prime==1){
            printf("%d is indeed a prime number\n",number);
        }else if(is_prime==0){
            printf("%d is unfortunately not a prime number\n",number);
        }
}
int main(){
    int number = 16;
    isPrime(number);
}