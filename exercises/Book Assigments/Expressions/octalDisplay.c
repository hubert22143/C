#include <stdio.h>
#include <math.h>
int main(void){
    int octalBase = 8;
    int number, i = 0;
    int octal_digits[6];
    printf("Enter a number between 0 and 32767 \n");
    scanf("%d",&number);
    if(number < 0 || number > 32767){
        printf("Invalid input! Enter a value within the range specified at beginning \n");
        return 0;
    }

    while(number!=0){
        octal_digits[i] = number % 8;
        number /= 8;
        i++;
    }
    printf("The octal representation is:0 \n");
    printf("Iterations: %d\n",i);

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal_digits[j]);
    }
    printf("\n");

    char user_prompt;
    printf("Re-convert the oct value to original value? y/n \n");
    scanf(" %c",&user_prompt);
    if(user_prompt == 'n' || user_prompt != 'n' && user_prompt != 'y'){
        printf("Closing the program");
        return 0;
    }else if (user_prompt=='y'){
        int original_value = 0;
        for(int j = i - 1; j>=0; j--){
            original_value += octal_digits[j] * pow(octalBase,j);
        }
        printf("Original value is: %d",original_value);
    }
}