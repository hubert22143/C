#include <stdio.h>

void swapPlaces(int *a, int *b) {
    if (*b > *a) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
int main() {
    int n;
    printf("Podaj ile chcesz wpisac liczb: ");
    scanf("%d", &n);

    int tab[n];
    printf("Podaj liczby, ktore maja zostac wpisane do tablicy:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    printf("Twoja tablica wyglada tak: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    int swapped;
    do {
        swapped = 0; // Resetujemy swapped na początku każdej iteracji
        for (int i = 0; i < n - 1; i++) {
            if (tab[i] < tab[i + 1]) { // Dla sortowania malejącego
                swapPlaces(&tab[i], &tab[i + 1]);
                swapped = 1; // Zmieniamy swapped na 1, jeśli zaszła zmiana
            }
        }
    } while (swapped); // Powtarzamy, dopóki były zamiany

    printf("Twoja tablica po zamianie miejsc wyglada tak: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}