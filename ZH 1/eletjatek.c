#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Nem kell feltétlen, 1/0 értékű inttel is megoldható
#include <stdint.h> // Nem feltétlen kell
#include <time.h>

// Mátrix kiíró függvény
void printMatrix(bool** matrix, const uint32_t meretX, const uint32_t meretY) {
    for (int i = 0; i < meretX; i++) {
        for (int j = 0; j < meretY; j++) {
            printf("%c", matrix[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
}

// Élő szomszédokat számoló fv
uint32_t eloSzomszedok(bool** matrix, const uint32_t coordX, const uint32_t coordY, const uint32_t meretX, const uint32_t meretY) {
    uint32_t ret = 0;
    for (int i = coordX - 1; i <= coordX + 1; i++) {
        if (i < 0 || i >= meretX) continue;
        for (int j = coordY - 1; j <= coordY + 1; j++) {
            if (j < 0 || j >= meretY) continue;
            ret += matrix[i][j]; // true == 1 -> számként hozzá lehet adni
        }
    }

    return ret;
}

int main() {
    const uint32_t meretX, meretY;
    bool** matrix;
    bool** kovetkezoLepes; // Egyszerűbb a következő lépés értékeit így tárolni

    printf("Mekkora legyen a jatekter X,Y formatumban? ");
    scanf_s("%d,%d", &meretX, &meretY);
    
    // Ha rossz méretet adtak meg
    if (meretX <= 0 || meretY <= 0) {
        printf("Rossz meretek lettek megadva!\n");
        exit(-1);
    }

    // Mátrixok létrehozása
    matrix = malloc(meretX * sizeof(bool*));
    kovetkezoLepes = malloc(meretX * sizeof(bool*));
    for (int i = 0; i < meretX; i++) {
        matrix[i] = calloc(meretY, sizeof(bool));
        kovetkezoLepes[i] = calloc(meretY, sizeof(bool));
    }

    // Első mátrix feltöltése
    uint32_t eloCellak;
    printf("Hany elo cellaval induljon a jatek? ");
    scanf_s("%d", &eloCellak);

    if (eloCellak <= 0) {
        printf("Rossz ertek lett megava az elo cellaknak!\n");
        exit(-1);
    }

    for (int i = 0; i < eloCellak; i++) {
        matrix[rand() % meretX][rand() % meretY] = true;
    }

    printf("Elso lepes:\n");
    printMatrix(matrix, meretX, meretY);
    printf("=============\nKovetkezo lepes:\n");

    // Következő lépés számítása
    for (int i = 0; i < meretX; i++) {
        for (int j = 0; j < meretY; j++) {
            const uint32_t szomszedszam = eloSzomszedok(matrix, i, j, meretX, meretY);
            if (szomszedszam == 3 || (szomszedszam == 2 && matrix[i][j]))
                kovetkezoLepes[i][j] = true;
        }
    }

    printMatrix(kovetkezoLepes, meretX, meretY);

    // Mátrix törlése
    for (int i = 0; i < meretX; i++) {
        free(kovetkezoLepes[i]);
        free(matrix[i]);
    }

    free(kovetkezoLepes);
    free(matrix);
}