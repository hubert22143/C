#include <stdio.h>
#include <math.h>

#define delta_formula(a,b,c) ((b)*(b) - 4*(a)*(c))
#define first_delta_x_result(a,b,delta) ((-b - sqrt(delta)) / (2 * a))
#define second_delta_x_result(a,b,delta) ((-b + sqrt(delta)) / (2 * a))

int main(void)
{
    /* 
    Zadanie 1 - Simple switch-case demonstration

    int nr;
    printf("Podaj numer \n");
    scanf("%d", &nr);

    switch(nr) {
        case 1: printf("!"); break;
        case 2: printf("-!"); break;
        case 3: printf("*- !"); break;
        default: break;
    }

    return 0;
    */

    /* 
    Zadanie 2 - Delta (discriminant) calculation and finding roots of a quadratic equation

    int a, b, c = 0;
    printf("Podaj argumenty w nastepujacej kolejnosci : a b c \n");
    printf("Na przyklad w postaci: 10 20 30\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Podane liczby to: %d %d %d \n", a, b, c);

    int delta = delta_formula(a, b, c);

    if (delta > 0) {
        printf("Delta ma dwa nastepujace rozwiazania \n");
        int x1 = first_delta_x_result(a, b, delta);
        printf("x1 wynosi: %d\n", x1);
        int x2 = second_delta_x_result(a, b, delta);
        printf("x2 wynosi: %d\n", x2);
    } else if (delta == 0) {
        printf("Delta ma jedno rozwiazanie \n");
        int x = first_delta_x_result(a, b, delta); // tylko jedno rozwiazanie
        printf("x wynosi: %d\n", x);
    } else {
        printf("Brak rozwiazan, delta jest ujemna \n");
    }
    */

    /* 
    Zadanie 3 - Find the maximum of three numbers

    int arr[3];
    printf("Podaj trzy liczby \n");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    int max = arr[0];
    for (int i = 1; i < 3; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    printf("Najwieksza z tych liczb to: %d ", max);
    */
}

/*
Zadanie 4 - Calculate the area of a cube, rectangle, or triangle

#include <stdio.h>
#include <stdlib.h>

int cube();
int rectangle();
int triangle();

int main()
{
    printf("Czego wymiary chcesz obliczyc? \n");
    printf("c - cube / r - rectangle / t - triangle\n");

    char user_input;
    scanf(" %c", &user_input);

    switch (user_input) {
        case 'c': cube(); break;
        case 'r': rectangle(); break;
        case 't': triangle(); break;
        default: break;
    }

    return 0;
}

int cube() {
    int a;
    printf("Podaj wymiar kwadrata, wpisz a \n");
    scanf("%d", &a);
    int pole = 4 * a;
    printf("Pole kwadrata wynosi: %d\n", pole);
    return pole;
}

int rectangle() {
    int a, b;
    printf("Podaj wymiary prostokata, wpisz w nastepujacej kolejnosci a oraz b\n");
    scanf("%d %d", &a, &b);
    int pole = (2 * a) + (2 * b);
    printf("Pole prostokata wynosi %d\n", pole);
    return pole;
}

int triangle() {
    int a, b, h;
    printf("Podaj a, b, oraz wysokosc \n");
    scanf("%d %d %d", &a, &b, &h);
    int pole = ((a + b) * h) / 2;
    printf("Pole trojkata wynosi %d\n", pole);
    return pole;
}
*/

/*
Zadanie 5 - Check if a triangle is valid and if it is a right triangle

#include <stdio.h>
#include <stdlib.h>

int check_if_triangle_is_possible(int a, int b, int h);

int main()
{
    int a, b, h;
    printf("Wpisz wartosci dla swojego trojkata w formacie(a,b,h): \n");
    scanf("%d %d %d", &a, &b, &h);
    check_if_triangle_is_possible(a, b, h);
    return 0;
}

int check_if_triangle_is_possible(int a, int b, int h) {
    if (a + b > h) {
        printf("Trojkat jest prawidlowy\n");

        int sumHolder = (a * a) + (b * b);
        int cHolder = h * h;

        if (sumHolder == cHolder) {
            printf("Trojkat jest prostokatny\n");
        }
    } else {
        printf("Trojkat nie jest prawidlowy\n");
    }
    return 0;
}
*/