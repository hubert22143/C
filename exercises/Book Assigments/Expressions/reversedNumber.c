#include <stdio.h>

int main(void){
int i = 0, reversed = 0;
printf("Write a number:\n");
scanf("%d",&i);
printf("Your written number is %d\n",i);

while (i!=0)
{
    int last_digit = i % 10;
    reversed = reversed * 10 + last_digit;
    i/= 10;
}

    printf("Your reversed number is: %d \n",reversed);


return 0;
}