#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free, srand, rand
#include <time.h> // time

#define NEPTUN_HOSSZ 6

int main() {
    // Random számgenerátor indítása
    srand((unsigned int) time(NULL));

    // nem kell dinamikus tömb, mert tudjuk a neptun kód
    // hosszát (6 karakter)
    char neptun[NEPTUN_HOSSZ];

    // Azért while-t használunk, mert i-t nem biztos növeljük
    int i = 0;
    while (i < NEPTUN_HOSSZ) {
        // Intervallum méretének meghatározása (hány különböző karakter lehet)
        char ujkar = rand() % ('Z' - 'A' + '9' - '0');
        
        // ujkar < 10 => Szám, egyébként betű
        if (ujkar < 10) ujkar += '0';
        else ujkar += 'A' - 10;

        // Ellenőrizzük, hogy benne van-e a tömbbe már
        int benne_van = 0;
        for (int j = 0; j < i; j++) {
            if (neptun[j] == ujkar) benne_van = 1;
        }
        // Ha nincs, bele lehet rakni
        if (!benne_van) {
            neptun[i] = ujkar;
            i++;
        }
    }

    printf("A generalt neptun kod: ");
    for (int i = 0; i < NEPTUN_HOSSZ; i++) {
        printf("%c", neptun[i]);
    }
}