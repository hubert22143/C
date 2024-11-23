#include <stdio.h>
int main(void){
    // ex 1 -----------------
    /*
    int i = 100;
    for(;i>0;i--){
        if(i%2==0){
            printf(" %d",i);
        }
    }
    
   int i = 100;
   do{
    i = i - 2;
    printf(" %d",i);
   }while(i>0);

    int i = 100;
    while(i>0){
        i = i - 2;
        printf(" %d",i);
    }
    */
   // ex 2 -----------------
   /*
   int user_input;
   printf("How many digits do you want to pass in? \n");
   scanf(" %d",&user_input);
   int arr[user_input];
   for(int i = 0; i<user_input; i++){
    printf("Write your %d number \n",i+1);
    scanf(" %d",&arr[i]);
   }
   int arrSum = 0;
   for(int i = 0; i < user_input ; i++){
    arrSum+= arr[i];
   }
   printf("Result of summed number is %d and it's average is %d \n",arrSum,(arrSum/user_input));
   */
   // ex 3 ------------------
   /*
   int a = 0;
   int b = 0;
   printf("Write two numbers \n");
   scanf(" %d%d",&a,&b);
   int division_holder = 0;
   do
   {
    division_holder = a % b;
    a = b;
    b = division_holder;
   } while (division_holder != 0);
   printf("")
    return 0;
}
*/