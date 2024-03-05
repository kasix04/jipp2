#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define ROZMIAR_TABLICY 5

int main() {
    int tablica[ROZMIAR_TABLICY] = { 1, 2, 3, 4, 5 };

    // Zapis do pliku binarnego
    FILE* plik_zapis = fopen("dane.bin", "wb");
    if (plik_zapis == NULL) {
        perror("Blad otwarcia pliku do zapisu");
        return 1;
    }

    fwrite(tablica, sizeof(int), ROZMIAR_TABLICY, plik_zapis);

    fclose(plik_zapis);

    // Wyzerowanie tablicy
    for (int i = 0; i < ROZMIAR_TABLICY; ++i) {
        tablica[i] = 0;
    }

    // Wczytywanie z pliku binarnego
    FILE* plik_odczyt = fopen("dane.bin", "rb");
    if (plik_odczyt == NULL) {
        perror("Blad otwarcia pliku do odczytu");
        return 1;
    }

    fread(tablica, sizeof(int), ROZMIAR_TABLICY, plik_odczyt);

    fclose(plik_odczyt);

    // Wyświetlanie zawartości tablicy na ekranie
    printf("Zawartosc tablicy po wczytaniu z pliku:\n");
    for (int i = 0; i < ROZMIAR_TABLICY; ++i) {
        printf("%d ", tablica[i]);
    }
    printf("\n");

    return 0;
}
