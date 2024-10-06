#include <stdio.h>
int leap_year(int n){
if((n%4==0 && n%100!=0) || (n % 400 ==0)){
    return 1;
}else{
    return 0;
}
}
int main(){
    int year;
    printf("Enter a year\n");
    scanf("%d",&year);
    if(leap_year(year)){
        printf("It is a leap year\n");
    }else{
        printf("It is not a leap year\n");
    }
}
