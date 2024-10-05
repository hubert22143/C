#include <stdio.h>
unsigned int tosquare(unsigned int n);
unsigned int tosquare(unsigned int n) {
    return n * n;
}
unsigned int square_of_sum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        sum += i;
    }
    return tosquare(sum);
}
unsigned int sum_of_squares(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        sum += tosquare(i);
    }
    return sum;
}
unsigned int difference_of_squares(unsigned int n){
    return square_of_sum(n) - sum_of_squares(n);
}
int main(){
    unsigned int sumofsquares = sum_of_squares(10);
    printf("%d\n",sumofsquares);
    unsigned int squareofsum = square_of_sum(10);
    printf("%d\n",squareofsum);
    unsigned int differenceofsquares = difference_of_squares(10);
    printf("%d\n",differenceofsquares);
}