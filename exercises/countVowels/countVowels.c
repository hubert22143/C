#include <stdio.h>
void countVowels(char* string){
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int counter = 0;
    for(int i = 0; string[i]!= '\0'; i++){
        for(int j = 0; j<9; j++){
            if(vowels[j]==string[i]){
                counter++;
            }
        }
    }
    printf("W tym stringu jest %d samoglosek",counter);
}
int main(){
    char* name = "Aleks";
    countVowels(name);
}