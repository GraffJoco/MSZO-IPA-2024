#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free, rand, srand
#include <time.h> // time

// 1. feladat
struct targy {
    int kredit;
    int jegy;
};

int main() {

    // 2. feladat
    int n;
    printf("Hany targyat vett fel a hallgato? ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("ERROR! Ennyi targyat nem vehetett fel a hallgato!\n");
        return -1; // exit(-1) is jó
    }

    // 3. feladat
    // Random számgenerátor indítása
    srand((unsigned int)time(NULL));

    // dinamikus tömb létrehozása
    struct targy* targyak = (struct targy*)malloc(n * sizeof(struct targy));

    for (int i = 0; i < n; i++) {
        // [a;b] random szám generálásánál
        // rand() % (b - a + 1) + a
        targyak[i].jegy = rand() % 5 + 1;
        targyak[i].kredit = rand() % 5 + 2;
        printf("%d. targy: %d kredit, %d jegy\n", i, targyak[i].kredit, targyak[i].jegy);
    }

    // 4. feladat
    int felvett = 0, teljesitett = 0;
    for (int i = 0; i < n; i++) {
        felvett += targyak[i].kredit;
        if (targyak[i].jegy != 1) {
            teljesitett += targyak[i].kredit;
        }
    }

    // Nem kötelező, de ajánlott minden tárgyat kiírni
    printf("Felvett: %d\nTeljesitett: %d\n", felvett, teljesitett);

    // 5. feladat
    int szumma = 0;

    for (int i = 0; i < n; i++) {
        // Ha bukott a tárgy, akkor a szummába nem számít be!
        if (targyak[i].jegy != 1) {
            szumma += targyak[i].jegy * targyak[i].kredit;
        }
    }

    // (double) szumma előtt -> műveleteknél nem vágja le a tizedesvessző utáni részt (pontos)
    const double KKI = (double)szumma / 30 * teljesitett / felvett;

    printf("A hallgato feleves KKI-ja: %lf\n", KKI);

    // Ezt el ne felejtsd!
    free(targyak);
}