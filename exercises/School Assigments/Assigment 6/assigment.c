/*
//Task 6
#include <stdio.h>

int countSumElementsFrom(int a,int b);

int main(void){

printf("From which number to which number do you want to sum elements divisible by 3 or 5? \n");

int fromFirst,toLast;

scanf("%d%d",&fromFirst,&toLast);

countSumElementsFrom(fromFirst,toLast);

return 0;

}

int countSumElementsFrom(int a,int b){

    int preSaveA = a;

    int sum = 0;

    do{

        if(a%3==0 || a%5==0){

            sum +=a;

        }

        if(a>=b){

            break;

        }

        a++;

    }while(a<=b);

   printf("The sum of numbers from %d to %d is %d",preSaveA,b,sum);

}
//Task 5
#include <stdio.h>

void grabThreeArguments(char character, int repeatHowManyTimes, int howManyRows);

int main(void){

printf("Enter the character you want to display: \n");

char znak;

scanf("%c",&znak);

printf("How many times do you want to display the character in one row? \n");

int repeat;

scanf("%d",&repeat);

printf("How many rows do you want to display this character again? \n");

int rows;

scanf("%d",&rows);

grabThreeArguments(znak,repeat,rows);

}

void grabThreeArguments(char character, int repeatHowManyTimes, int howManyRows){

for(int i = 0; i<howManyRows;i++){

    printf("\n");

    for(int j = 0;  j < repeatHowManyTimes ; j++){

        printf("%c",character);

    }

}

}
//Task 4
#include <stdio.h>

int silnia(n);

int newtonSymbol(n,k);

int main(void){

int n,k;

printf("Enter the binomial coefficients n and k\n");

scanf("%d%d",&n,&k);

newtonSymbol(n,k);

return 0;

}

int silnia(n){

    int factorial = 1;

for(int i = n; i > 1; i--){

    factorial *=i;

}

    return factorial;

}

int newtonSymbol(n,k){

    if(k>n){

        printf("Result is 0, k cannot be greater than n \n");

        return 0;

    }

    int nFactorial = silnia(n);

    int kFactorial = silnia(k);

    int nMinusKFactorial = silnia(n-k);

    int pattern = 0;

    pattern = nFactorial/(kFactorial*nMinusKFactorial);

    printf("The result of this binomial coefficient is %d \n",pattern);

}
//Task 3
#include <stdio.h>

void silnia(n);

int main(void){

int n;

printf("Enter the number to calculate its factorial: \n");

scanf("%d",&n);

silnia(n);

return 0;

}

void silnia(n){

    int factorial = 1;

for(int i = n; i > 1; i--){

    factorial *=i;

}

    printf("The factorial of this number is %d \n",factorial);

}
//Task 2
#include <stdio.h>

void objetoscR();

void objetoscD (float a, float b, float h);

float objetoscT (float a, float b, float h);

int main(void){

    int a = 0;

    int b = 0;

    int h = 0;

printf("Enter the dimensions of the cuboid in the following format: a b h\n");

scanf("%d%d%d",&a,&b,&h);

objetoscD(a,b,h);

int cuboidVolume = objetoscT(a,b,h);

printf("The volume of the cuboid is: %d \n",cuboidVolume);

objetoscR();

return 0;

}

void objetoscR(){

    int a = 0;

    int b = 0;

    int h = 0;

printf("Enter a, b, and h \n");

    scanf("%d%d%d",&a,&b,&h);

    int volume = a * b * h;

    printf("The volume of this cuboid is %d\n",volume);

}

void objetoscD(float a, float b, float h){

    int volume = a * b * h;

    printf("The volume of this cuboid is %d\n",volume);

}

float objetoscT (float a, float b, float h){

    int volume = a * b * h;

    printf("The volume is %d\n",volume);

    return volume;

}
//Task 1a ,Task 1b
#include <stdio.h>

void wypisz(); // declaration (prototype) of the function

int main()

{

    printf("I will now run the wypisz function \n");

    wypisz();

     printf("The function has already been executed \n");

    return 0;

}

void wypisz() // definition of the function

{

     printf("I am a function that prints \n");

 }
 #include <stdio.h>

void wypisz() // definition of the function

{

     printf("I am a function that prints \n");

 }

int main()

{

    printf("I will now run the wypisz function \n");

    wypisz();

     printf("The function has already been executed \n");

    return 0;

}
*/